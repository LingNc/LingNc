#include "hdfile.h"
#include "pair.h"
#include "huffcode.h"
#include <stdlib.h>
#include <string.h>

// 用于二分查找的比较函数
// 注意：bsearchf调用check(key, p[mid])，所以第一个参数是key，第二个是item
static bool utf8_check(any key, any item) {
    utf8 target = *(utf8*)key;
    pair p = *(pair*)item;
    utf8 ch = visitp_cast(utf8, p->first);
    return target <= ch;  // 改为 <= 以匹配二分查找逻辑
}

// 创建文件处理器
hdfile new_hdfile() {
    hdfile self = malloc(sizeof(HandleFile));
    if (self == NULL) return NULL;

    self->_indata = NULL;
    self->_outdata = NULL;
    self->buffer = NULL;
    self->size = BUFFER_0_SIZE;
    self->bit_pos = 0;
    self->buffer_pos = 0;

    // 分配缓冲区
    self->buffer = malloc(self->size);
    if (self->buffer == NULL) {
        free(self);
        return NULL;
    }
    memset(self->buffer, 0, self->size);

    return self;
}

// 打开文件
Exception hdfile_open(hdfile self, const char *input_path, const char *output_path) {
    if (self == NULL) return new_exception(ERROR, "hdfile为空");

    if (input_path != NULL) {
        self->_indata = fopen(input_path, "rb");
        if (self->_indata == NULL) {
            return new_exception(ERROR, "无法打开输入文件");
        }
    }

    if (output_path != NULL) {
        self->_outdata = fopen(output_path, "wb");
        if (self->_outdata == NULL) {
            if (self->_indata) fclose(self->_indata);
            return new_exception(ERROR, "无法打开输出文件");
        }
    }

    return new_exception(SUCCESS, "文件打开成功");
}

// 关闭文件
void hdfile_close(hdfile self) {
    if (self == NULL) return;

    if (self->_indata) {
        fclose(self->_indata);
        self->_indata = NULL;
    }

    if (self->_outdata) {
        fclose(self->_outdata);
        self->_outdata = NULL;
    }
}

// 释放文件处理器
void free_hdfile(hdfile self) {
    if (self == NULL) return;

    hdfile_close(self);
    if (self->buffer) {
        free(self->buffer);
    }
    free(self);
}

// 读取文件并统计UTF8字符频率
sqlist hdfile_count_frequency(hdfile self) {
    if (self == NULL || self->_indata == NULL) return NULL;

    // printf("DEBUG: 开始统计字符频率\n");

    // 创建频率表的接口 sqlist<pair<utf8, size_t>>
    interfaces pair_inters = new_interfaces(NULL, 2,
        new_interface(sizeof(utf8), NULL, ""),
        new_interface(sizeof(size_t), NULL, "")
    );

    // printf("DEBUG: 创建pair接口成功\n");

    // 创建频率表
    sqlist freq_table = new_sqlist(pair_create_inters());
    if (freq_table == NULL) {
        // printf("DEBUG: 创建频率表失败\n");
        return NULL;
    }

    // printf("DEBUG: 创建频率表成功\n");

    // 读取文件并统计频率
    rewind(self->_indata);

    // printf("DEBUG: 开始读取文件\n");
    // 读取整个文件到缓冲区
    while (!feof(self->_indata)) {
        size_t bytes_read = fread(self->buffer, 1, self->size, self->_indata);
        if (bytes_read == 0) break;

        // printf("DEBUG: 读取了 %zu 字节\n", bytes_read);

        // 处理每个UTF8字符 - 使用正确的UTF8解析
        for (size_t i = 0; i < bytes_read; ) {
            utf8 ch;
            int utf8_bytes = read_utf8(&ch, self->buffer, i, bytes_read);
            if (utf8_bytes <= 0) {
                // 如果UTF8解析失败，跳过这个字节
                i++;
                continue;
            }

            // if (i < 50) printf("DEBUG: 处理UTF8字符 %lu (占%d字节)\n", ch, utf8_bytes);

            // 在频率表中查找字符（简化版本，不按顺序插入）
            bool found = false;
            for (size_t j = 0; j < sqlist_size(freq_table); j++) {
                pair p = *(pair*)sqlist_at(freq_table, j);
                utf8 existing_ch = visitp_cast(utf8, p->first);

                if (existing_ch == ch) {
                    // 字符已存在，增加频率
                    size_t *freq_ptr = (size_t*)p->second;
                    (*freq_ptr)++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                // 字符不存在，直接添加到末尾
                size_t freq = 1;
                pair new_p = new_pair(&ch, &freq, pair_inters);
                if (new_p == NULL) {
                    // printf("DEBUG: new_pair 失败\n");
                    return NULL;
                }
                sqlist_push_back(freq_table, &new_p);
            }

            i += utf8_bytes; // 正确增加索引
        }
    }

    // 按频率降序排序 - 使用简单的选择排序
    size_t table_size = sqlist_size(freq_table);
    for (size_t i = 0; i < table_size - 1; i++) {
        size_t max_idx = i;
        pair p_max = *(pair*)sqlist_at(freq_table, i);
        size_t max_freq = visitp_cast(size_t, p_max->second);

        // 找到最大频率的位置
        for (size_t j = i + 1; j < table_size; j++) {
            pair p_j = *(pair*)sqlist_at(freq_table, j);
            size_t freq_j = visitp_cast(size_t, p_j->second);
            if (freq_j > max_freq) {
                max_freq = freq_j;
                max_idx = j;
            }
        }

        // 交换位置i和max_idx的元素
        if (max_idx != i) {
            pair p_i = *(pair*)sqlist_at(freq_table, i);
            pair p_max_new = *(pair*)sqlist_at(freq_table, max_idx);

            // 临时保存
            pair temp = p_i;

            // 交换
            sqlist_set(freq_table, i, &p_max_new);
            sqlist_set(freq_table, max_idx, &temp);
        }
    }

    // printf("DEBUG: 统计完成，总字符种类: %zu\n", sqlist_size(freq_table));
    return freq_table;
}

// 写入字长表到文件（优化版本）
Exception hdfile_write_length_table(hdfile self, sqlist length_table) {
    if (self == NULL || self->_outdata == NULL || length_table == NULL) {
        return new_exception(ERROR, "参数错误");
    }

    // 写入字长表大小（使用uint32_t，支持最多42亿个字符，绝对安全）
    uint32_t table_size = (uint32_t)sqlist_size(length_table);
    fwrite(&table_size, sizeof(uint32_t), 1, self->_outdata);

    // 写入字长表数据（优化格式：4字节字符 + 1字节长度）
    for (uint32_t i = 0; i < table_size; i++) {
        pair p = *(pair*)sqlist_at(length_table, i);
        utf8 ch = visitp_cast(utf8, p->first);
        size_t length = visitp_cast(size_t, p->second);

        // UTF8字符用4字节存储（支持所有Unicode字符）
        uint32_t ch_compact = (uint32_t)ch;
        fwrite(&ch_compact, sizeof(uint32_t), 1, self->_outdata);

        // 编码长度用1字节足够（哈夫曼编码长度通常不超过64位）
        uint8_t length_compact = (uint8_t)length;
        fwrite(&length_compact, sizeof(uint8_t), 1, self->_outdata);
    }

    return new_exception(SUCCESS, "字长表写入成功");
}

// 从文件读取字长表（优化版本）
sqlist hdfile_read_length_table(hdfile self) {
    if (self == NULL || self->_indata == NULL) return NULL;

    // 读取字长表大小（uint32_t格式）
    uint32_t table_size;
    if (fread(&table_size, sizeof(uint32_t), 1, self->_indata) != 1) {
        return NULL;
    }

    // 创建用于存储pair指针的接口
    interfaces pair_ptr_inters = pair_ptr_create_inters();
    sqlist length_table = new_sqlist(pair_ptr_inters);

    // 创建字长表pair的接口，在循环外创建一次，所有pair共用
    interfaces length_inters = new_interfaces(NULL, 2,
        new_interface(sizeof(utf8), NULL, ""),
        new_interface(sizeof(size_t), NULL, "")
    );

    // 读取字长表数据（优化格式：4字节字符 + 1字节长度）
    for (uint32_t i = 0; i < table_size; i++) {
        uint32_t ch_compact;
        uint8_t length_compact;

        if (fread(&ch_compact, sizeof(uint32_t), 1, self->_indata) != 1 ||
            fread(&length_compact, sizeof(uint8_t), 1, self->_indata) != 1) {
            free_sqlist(length_table);
            free_interfaces(length_inters);
            return NULL;
        }

        // 转换为原始类型
        utf8 ch = (utf8)ch_compact;
        size_t length = (size_t)length_compact;

        // 直接存储值，而不是指针
        pair p = new_pair(&ch, &length, length_inters);
        sqlist_push_back(length_table, &p);
    }

    return length_table;
}

// 编码文件内容
Exception hdfile_encode(hdfile self, sqlist code_table) {
    if (self == NULL || self->_indata == NULL || self->_outdata == NULL || code_table == NULL) {
        return new_exception(ERROR, "参数错误");
    }

    // 重置输入文件位置
    rewind(self->_indata);

    // 创建单独的读取缓冲区和写入缓冲区
    byte read_buffer = malloc(self->size);
    byte write_buffer = malloc(self->size);
    if (read_buffer == NULL || write_buffer == NULL) {
        if (read_buffer) free(read_buffer);
        if (write_buffer) free(write_buffer);
        return new_exception(ERROR, "内存分配失败");
    }

    // 初始化位写入
    size_t bit_pos = 0;
    size_t buffer_pos = 0;
    memset(write_buffer, 0, self->size);

    size_t total_bits = 0;

    // 读取并编码文件
    while (!feof(self->_indata)) {
        // 读取数据到读取缓冲区
        size_t bytes_read = fread(read_buffer, 1, self->size, self->_indata);
        if (bytes_read == 0) break;

        // 处理每个UTF8字符
        for (size_t i = 0; i < bytes_read; ) {
            utf8 ch;
            int utf8_bytes = read_utf8(&ch, read_buffer, i, bytes_read);

            if (utf8_bytes < 0) {
                // UTF-8字符跨越缓冲区边界
                // 将文件指针回退到当前位置，重新以更大缓冲区读取
                long current_pos = ftell(self->_indata);
                fseek(self->_indata, current_pos - bytes_read + i, SEEK_SET);
                break;  // 退出当前缓冲区处理，重新读取
            } else if (utf8_bytes == 0) {
                i++;
                continue;
            }

            // 在编码表中使用二分查找字符
            huffcode code = NULL;
            // printf("DEBUG: 在编码表中查找字符 %lu\n", ch);

            // 先尝试线性查找，看看字符是否在表中
            bool found_linear = false;
            for (size_t j = 0; j < sqlist_size(code_table); j++) {
                pair p = *(pair*)sqlist_at(code_table, j);
                utf8 table_ch = visitp_cast(utf8, p->first);
                if (table_ch == ch) {
                    code = (huffcode)p->second;
                    found_linear = true;
                    // printf("DEBUG: 线性查找找到字符 %lu\n", ch);
                    break;
                }
            }

            if (!found_linear) {
                // printf("DEBUG: 线性查找未找到字符 %lu\n", ch);
                // 打印编码表中的所有字符
                // printf("DEBUG: 编码表包含的字符：");
                for (size_t j = 0; j < sqlist_size(code_table); j++) {
                    pair p = *(pair*)sqlist_at(code_table, j);
                    utf8 table_ch = visitp_cast(utf8, p->first);
                    // printf(" %lu", table_ch);
                }
                // printf("\n");
            }

            if (code != NULL) {
                // printf("DEBUG: 编码字符 %lu, 编码长度: %u, 编码值: %lu\n",
                //        ch, code->_size, code->_code);

                // 写入编码位
                for (Byte bit = 0; bit < code->_size; bit++) {
                    bool bit_value = huffcode_get(code, bit);
                    // printf("DEBUG: 写入位 %u: %d\n", bit, bit_value ? 1 : 0);

                    if (bit_value) {
                        // 写入1
                        write_buffer[buffer_pos] |= (1 << (7 - bit_pos));
                    }

                    bit_pos++;
                    total_bits++;

                    if (bit_pos == 8) {
                        bit_pos = 0;
                        buffer_pos++;

                        // 如果缓冲区满了，写入文件
                        if (buffer_pos >= self->size) {
                            fwrite(write_buffer, 1, buffer_pos, self->_outdata);
                            memset(write_buffer, 0, self->size);
                            buffer_pos = 0;
                        }
                    }
                }
                // printf("DEBUG: 字符编码完成，当前总位数: %zu\n", total_bits);
            } else {
                // printf("DEBUG: 警告 - 字符 %lu 在编码表中未找到\n", ch);
            }

            i += utf8_bytes;
        }
    }

    // 写入剩余的缓冲区
    if (buffer_pos > 0 || bit_pos > 0) {
        // 如果有未满8位的数据，需要包含当前字节
        size_t bytes_to_write = buffer_pos;
        if (bit_pos > 0) {
            bytes_to_write = buffer_pos + 1;
        }
        fwrite(write_buffer, 1, bytes_to_write, self->_outdata);
    }

    // 写入总位数
    fwrite(&total_bits, sizeof(size_t), 1, self->_outdata);

    // 清理缓冲区
    free(read_buffer);
    free(write_buffer);

    return new_exception(SUCCESS, "编码完成");
}

// 解码文件内容
Exception hdfile_decode(hdfile self, hufftree tree) {
    if (self == NULL || self->_indata == NULL || self->_outdata == NULL) {
        return new_exception(ERROR, "参数错误");
    }

    // printf("DEBUG: 开始解码\n");

    // 如果没有提供树，从字长表重建
    bool need_free_tree = false;
    if (tree == NULL) {
        // printf("DEBUG: 没有提供哈夫曼树，从文件中重建\n");

        // 读取字长表
        rewind(self->_indata);
        sqlist length_table = hdfile_read_length_table(self);
        if (length_table == NULL) {
            // printf("DEBUG: 读取字长表失败\n");
            return new_exception(ERROR, "无法读取字长表");
        }

        // printf("DEBUG: 字长表读取成功，开始重建哈夫曼树\n");

        // 从字长表创建编码表
        sqlist code_table = create_canonical_from_length(length_table);
        if (code_table == NULL) {
            // printf("DEBUG: 创建编码表失败\n");
            free_sqlist(length_table);
            return new_exception(ERROR, "无法创建编码表");
        }

        // 从编码表构建哈夫曼树
        tree = hufftree_from_code_table(code_table);
        if (tree == NULL) {
            // printf("DEBUG: 构建哈夫曼树失败\n");
            free_sqlist(length_table);
            free_sqlist(code_table);
            return new_exception(ERROR, "无法构建哈夫曼树");
        }

        need_free_tree = true;
        free_sqlist(length_table);
        free_sqlist(code_table);

        // printf("DEBUG: 哈夫曼树重建成功\n");
    } else {
        // printf("DEBUG: 使用提供的哈夫曼树\n");
        // 跳过字长表
        rewind(self->_indata);
        sqlist temp_table = hdfile_read_length_table(self);
        if (temp_table) {
            // printf("DEBUG: 字长表读取成功，释放临时表\n");
            free_sqlist(temp_table);
        } else {
            // printf("DEBUG: 字长表读取失败\n");
            return new_exception(ERROR, "无法读取字长表");
        }
    }

    // printf("DEBUG: 检查树指针: %p\n", (void*)tree);

    // 验证树结构
    if (tree->left == NULL && tree->right == NULL) {
        // printf("DEBUG: 根节点是叶子节点，字符: %lu\n", tree->word);
    } else {
        // printf("DEBUG: 根节点有子节点，左子树: %p，右子树: %p\n", (void*)tree->left, (void*)tree->right);
    }

    // 读取总位数
    // printf("DEBUG: 准备读取总位数\n");
    fseek(self->_indata, -sizeof(size_t), SEEK_END);
    size_t total_bits;
    if (fread(&total_bits, sizeof(size_t), 1, self->_indata) != 1) {
        // printf("DEBUG: 读取总位数失败\n");
        if (need_free_tree) free_hufftree(tree);
        return new_exception(ERROR, "无法读取总位数");
    }

    // printf("DEBUG: 读取到总位数: %zu\n", total_bits);

    // 回到编码数据开始位置（跳过字长表）
    // printf("DEBUG: 准备读取字长表\n");
    rewind(self->_indata);
    sqlist temp_table = hdfile_read_length_table(self);
    if (temp_table) {
        // printf("DEBUG: 字长表读取成功，释放临时表\n");
        free_sqlist(temp_table);
    } else {
        // printf("DEBUG: 字长表读取失败\n");
        if (need_free_tree) free_hufftree(tree);
        return new_exception(ERROR, "无法读取字长表");
    }

    // printf("DEBUG: 开始解码位数据\n");
    // 解码
    huffnode current = tree;
    size_t decoded_bits = 0;

    while (decoded_bits < total_bits) {
        // 读取数据到缓冲区
        size_t bytes_read = fread(self->buffer, 1, self->size, self->_indata);
        if (bytes_read == 0) break;

        for (size_t i = 0; i < bytes_read && decoded_bits < total_bits; i++) {
            for (int bit = 7; bit >= 0 && decoded_bits < total_bits; bit--) {
                decoded_bits++;

                // 根据位值移动到左或右子树
                if (self->buffer[i] & (1 << bit)) {
                    current = current->right;
                } else {
                    current = current->left;
                }

                // 检查current是否为NULL
                if (current == NULL) {
                    if (need_free_tree) free_hufftree(tree);
                    return new_exception(ERROR, "解码错误：遇到无效的树节点");
                }

                // 如果到达叶子节点
                if (current->left == NULL && current->right == NULL) {
                    // 输出字符
                    // 将UTF8字符转换为字节序列
                    unsigned char utf8_bytes[4];
                    int len = 0;

                    if (current->word <= 0x7F) {
                        utf8_bytes[0] = (unsigned char)current->word;
                        len = 1;
                    } else if (current->word <= 0x7FF) {
                        utf8_bytes[0] = (unsigned char)(0xC0 | (current->word >> 6));
                        utf8_bytes[1] = (unsigned char)(0x80 | (current->word & 0x3F));
                        len = 2;
                    } else if (current->word <= 0xFFFF) {
                        utf8_bytes[0] = (unsigned char)(0xE0 | (current->word >> 12));
                        utf8_bytes[1] = (unsigned char)(0x80 | ((current->word >> 6) & 0x3F));
                        utf8_bytes[2] = (unsigned char)(0x80 | (current->word & 0x3F));
                        len = 3;
                    } else {
                        utf8_bytes[0] = (unsigned char)(0xF0 | (current->word >> 18));
                        utf8_bytes[1] = (unsigned char)(0x80 | ((current->word >> 12) & 0x3F));
                        utf8_bytes[2] = (unsigned char)(0x80 | ((current->word >> 6) & 0x3F));
                        utf8_bytes[3] = (unsigned char)(0x80 | (current->word & 0x3F));
                        len = 4;
                    }

                    fwrite(utf8_bytes, 1, len, self->_outdata);
                    current = tree; // 回到根节点
                }
            }
        }
    }

    // 清理资源
    if (need_free_tree) free_hufftree(tree);

    return new_exception(SUCCESS, "解码完成");
}