#include "hdfile.h"
#include "pair.h"
#include "huffcode.h"
#include <stdlib.h>
#include <string.h>

// 用于二分查找的比较函数
static bool utf8_check(any item, any key) {
    pair p = *(pair*)item;
    utf8 ch = visitp_cast(utf8, p->first);
    utf8 target = *(utf8*)key;
    return ch >= target;
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

    printf("DEBUG: 开始统计字符频率\n");

    // 创建频率表的接口 sqlist<pair<utf8, size_t>>
    interfaces pair_inters = new_interfaces(NULL, 2,
        new_interface(sizeof(utf8), NULL, ""),
        new_interface(sizeof(size_t), NULL, "")
    );

    printf("DEBUG: 创建pair接口成功\n");

    // 创建频率表
    sqlist freq_table = new_sqlist(pair_create_inters());
    if (freq_table == NULL) {
        printf("DEBUG: 创建频率表失败\n");
        return NULL;
    }

    printf("DEBUG: 创建频率表成功\n");

    // 读取文件并统计频率
    rewind(self->_indata);

    printf("DEBUG: 开始读取文件\n");    // 读取整个文件到缓冲区
    while (!feof(self->_indata)) {
        size_t bytes_read = fread(self->buffer, 1, self->size, self->_indata);
        if (bytes_read == 0) break;

        printf("DEBUG: 读取了 %zu 字节\n", bytes_read);

        // 处理每个UTF8字符 (简化版本，先只处理基本字符)
        for (size_t i = 0; i < bytes_read; i++) {
            utf8 ch = self->buffer[i]; // 简化：直接使用字节值

            if (i < 10) printf("DEBUG: 处理字符 %u\n", (unsigned)ch);

            // 在频率表中查找字符
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
                } else if (existing_ch > ch) {
                    // 找到插入位置，插入新字符
                    size_t freq = 1;
                    pair new_p = new_pair(&ch, &freq, pair_inters);
                    if (new_p == NULL) {
                        printf("DEBUG: new_pair 失败\n");
                        return NULL;
                    }
                    sqlist_insert(freq_table, j, &new_p);
                    found = true;
                    break;
                }
            }

            if (!found) {
                // 字符不存在且应该插入到末尾
                size_t freq = 1;
                pair new_p = new_pair(&ch, &freq, pair_inters);
                if (new_p == NULL) {
                    printf("DEBUG: new_pair 失败\n");
                    return NULL;
                }
                sqlist_push_back(freq_table, &new_p);
            }
        }
    }

    printf("DEBUG: 统计完成，总字符种类: %zu\n", sqlist_size(freq_table));
    return freq_table;
}

// 写入字长表到文件
Exception hdfile_write_length_table(hdfile self, sqlist length_table) {
    if (self == NULL || self->_outdata == NULL || length_table == NULL) {
        return new_exception(ERROR, "参数错误");
    }

    // 写入字长表大小
    size_t table_size = sqlist_size(length_table);
    fwrite(&table_size, sizeof(size_t), 1, self->_outdata);

    // 写入字长表数据
    for (size_t i = 0; i < table_size; i++) {
        pair p = *(pair*)sqlist_at(length_table, i);
        utf8 ch = visitp_cast(utf8, p->first);
        size_t length = visitp_cast(size_t, p->second);

        fwrite(&ch, sizeof(utf8), 1, self->_outdata);
        fwrite(&length, sizeof(size_t), 1, self->_outdata);
    }

    return new_exception(SUCCESS, "字长表写入成功");
}

// 从文件读取字长表
sqlist hdfile_read_length_table(hdfile self) {
    if (self == NULL || self->_indata == NULL) return NULL;

    // 读取字长表大小
    size_t table_size;
    if (fread(&table_size, sizeof(size_t), 1, self->_indata) != 1) {
        return NULL;
    }

    // 创建字长表
    interfaces length_inters = new_interfaces(NULL, 2,
        new_interface(sizeof(utf8), NULL, ""),
        new_interface(sizeof(size_t), NULL, "")
    );
    sqlist length_table = new_sqlist(pair_create_inters());

    // 读取字长表数据
    for (size_t i = 0; i < table_size; i++) {
        utf8 ch;
        size_t length;

        if (fread(&ch, sizeof(utf8), 1, self->_indata) != 1 ||
            fread(&length, sizeof(size_t), 1, self->_indata) != 1) {
            free_sqlist(length_table);
            return NULL;
        }

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

    // 初始化位写入
    self->bit_pos = 0;
    self->buffer_pos = 0;
    memset(self->buffer, 0, self->size);

    size_t total_bits = 0;

    // 读取并编码文件
    while (!feof(self->_indata)) {
        // 读取数据到缓冲区
        size_t bytes_read = fread(self->buffer, 1, self->size, self->_indata);
        if (bytes_read == 0) break;

        // 处理每个UTF8字符
        for (size_t i = 0; i < bytes_read; ) {
            utf8 ch;
            int utf8_bytes = read_utf8(&ch, self->buffer, i, bytes_read);
            if (utf8_bytes <= 0) {
                i++;
                continue;
            }

            // 在编码表中使用二分查找字符
            huffcode code = NULL;
            any found_item = sqlist_bsearchf(code_table, &ch, utf8_check);
            if (found_item != NULL) {
                pair p = *(pair*)found_item;
                if (visitp_cast(utf8, p->first) == ch) {
                    code = (huffcode)p->second;
                }
            }

            if (code != NULL) {
                // 写入编码位
                for (Byte bit = 0; bit < code->_size; bit++) {
                    if (huffcode_get(code, bit)) {
                        // 写入1
                        self->buffer[self->buffer_pos] |= (1 << (7 - self->bit_pos));
                    }

                    self->bit_pos++;
                    total_bits++;

                    if (self->bit_pos == 8) {
                        self->bit_pos = 0;
                        self->buffer_pos++;

                        // 如果缓冲区满了，写入文件
                        if (self->buffer_pos >= self->size) {
                            fwrite(self->buffer, 1, self->buffer_pos, self->_outdata);
                            memset(self->buffer, 0, self->size);
                            self->buffer_pos = 0;
                        }
                    }
                }
            }

            i += utf8_bytes;
        }
    }

    // 写入剩余的缓冲区
    if (self->buffer_pos > 0 || self->bit_pos > 0) {
        if (self->bit_pos > 0) self->buffer_pos++;
        fwrite(self->buffer, 1, self->buffer_pos, self->_outdata);
    }

    // 写入总位数
    fwrite(&total_bits, sizeof(size_t), 1, self->_outdata);

    return new_exception(SUCCESS, "编码完成");
}

// 解码文件内容
Exception hdfile_decode(hdfile self, hufftree tree) {
    if (self == NULL || self->_indata == NULL || self->_outdata == NULL || tree == NULL) {
        return new_exception(ERROR, "参数错误");
    }

    // 读取总位数
    fseek(self->_indata, -sizeof(size_t), SEEK_END);
    size_t total_bits;
    if (fread(&total_bits, sizeof(size_t), 1, self->_indata) != 1) {
        return new_exception(ERROR, "无法读取总位数");
    }

    // 回到编码数据开始位置（跳过字长表）
    rewind(self->_indata);
    sqlist temp_table = hdfile_read_length_table(self);
    if (temp_table) {
        free_sqlist(temp_table);
    }

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

                // 如果到达叶子节点
                if (current->left == NULL && current->right == NULL) {                    // 输出字符
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

    return new_exception(SUCCESS, "解码完成");
}