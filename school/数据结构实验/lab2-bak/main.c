#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "huffman.h"
#include "hdfile.h"
#include "tools.h"
#include "pair.h"

// 将UTF-8码点转换为UTF-8字节序列
void utf8_to_bytes(utf8 ch, char *utf8_str) {
    if (ch <= 0x7F) {
        // 单字节字符 (ASCII)
        utf8_str[0] = (char)ch;
        utf8_str[1] = '\0';
    } else if (ch <= 0x7FF) {
        // 双字节字符
        utf8_str[0] = (char)(0xC0 | (ch >> 6));
        utf8_str[1] = (char)(0x80 | (ch & 0x3F));
        utf8_str[2] = '\0';
    } else if (ch <= 0xFFFF) {
        // 三字节字符
        utf8_str[0] = (char)(0xE0 | (ch >> 12));
        utf8_str[1] = (char)(0x80 | ((ch >> 6) & 0x3F));
        utf8_str[2] = (char)(0x80 | (ch & 0x3F));
        utf8_str[3] = '\0';
    } else {
        // 四字节字符
        utf8_str[0] = (char)(0xF0 | (ch >> 18));
        utf8_str[1] = (char)(0x80 | ((ch >> 12) & 0x3F));
        utf8_str[2] = (char)(0x80 | ((ch >> 6) & 0x3F));
        utf8_str[3] = (char)(0x80 | (ch & 0x3F));
        utf8_str[4] = '\0';
    }
}

// 显示UTF8字符信息
void display_utf8_info(utf8 ch, huffcode code) {
    printf("U+%04lX\t", ch);

    // 显示字符本身
    if (ch >= 32 && ch <= 126) {
        // ASCII可打印字符
        printf("%c\t\t", (char)ch);
    } else if (ch == 10) {
        printf("\\n\t\t");
    } else if (ch == 13) {
        printf("\\r\t\t");
    } else if (ch == 9) {
        printf("\\t\t\t");
    } else if (ch == 32) {
        printf("空格\t\t");
    } else if (ch < 32) {
        printf("控制字符\t");
    } else {
        // UTF-8字符，转换并输出
        char utf8_str[5];
        utf8_to_bytes(ch, utf8_str);
        printf("%s\t\t", utf8_str);
    }

    // 显示编码
    printf("编码: ");
    for (Byte i = 0; i < code->_size; i++) {
        // 从最高有效位开始读取
        Byte bit_pos = code->_size - 1 - i;
        bool bit = (code->_code >> bit_pos) & 1;
        printf("%d", bit ? 1 : 0);
    }
    printf("\n");
}

// 获取文件大小
long get_file_size(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return -1;

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);
    return size;
}

// 比较两个文件是否相同
int compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");

    if (!f1 || !f2) {
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return 0;
    }

    int ch1, ch2;
    do {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);
    } while (ch1 == ch2 && ch1 != EOF);

    fclose(f1);
    fclose(f2);

    return (ch1 == ch2);
}

// 输出频率表到文件
void output_frequency_table(sqlist freq_table, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("警告：无法创建频率表文件 %s\n", filename);
        return;
    }

    fprintf(fp, "字符频率统计表\n");
    fprintf(fp, "================\n");
    fprintf(fp, "总字符数: %zu\n\n", sqlist_size(freq_table));
    fprintf(fp, "Unicode码\t字符\t\t频率\t\t百分比\n");
    fprintf(fp, "--------\t----\t\t----\t\t------\n");

    // 计算总频率
    size_t total_freq = 0;
    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        size_t freq = *(size_t*)p->second;
        total_freq += freq;
    }

    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        utf8 ch = visitp_cast(utf8, p->first);
        size_t freq = *(size_t*)p->second;
        double percentage = (double)freq / total_freq * 100.0;

        fprintf(fp, "U+%04lX\t\t", ch);

        // 显示字符本身（如果可打印）
        if (ch >= 32 && ch <= 126) {
            fprintf(fp, "%c\t\t", (char)ch);
        } else if (ch == 10) {
            fprintf(fp, "\\n\t\t");
        } else if (ch == 13) {
            fprintf(fp, "\\r\t\t");
        } else if (ch == 9) {
            fprintf(fp, "\\t\t\t");
        } else if (ch == 32) {
            fprintf(fp, "空格\t\t");
        } else if (ch < 32) {
            fprintf(fp, "控制字符\t");
        } else {
            // UTF-8字符，使用统一函数转换输出
            char utf8_str[5];
            utf8_to_bytes(ch, utf8_str);
            fprintf(fp, "%s\t\t", utf8_str);
        }

        fprintf(fp, "%zu\t\t%.3f%%\n", freq, percentage);
    }

    fprintf(fp, "\n总计:\t\t\t%zu\t\t100.000%%\n", total_freq);
    fclose(fp);
    printf("✓ 频率表已保存到: %s\n", filename);
}

// 输出编码表到文件
void output_encoding_table(sqlist code_table, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("警告：无法创建编码表文件 %s\n", filename);
        return;
    }

    fprintf(fp, "哈夫曼编码表\n");
    fprintf(fp, "============\n");
    fprintf(fp, "编码字符数: %zu\n\n", sqlist_size(code_table));
    fprintf(fp, "Unicode码\t字符\t\t编码\t\t\t长度\n");
    fprintf(fp, "--------\t----\t\t----\t\t\t----\n");

    // 统计编码长度分布
    size_t length_dist[65] = {0}; // 最多64位编码
    size_t total_bits = 0;

    for (size_t i = 0; i < sqlist_size(code_table); i++) {
        pair p = *(pair*)sqlist_at(code_table, i);
        utf8 ch = visitp_cast(utf8, p->first);
        huffcode code = (huffcode)p->second;

        fprintf(fp, "U+%04lX\t\t", ch);

        // 显示字符本身（如果可打印）
        if (ch >= 32 && ch <= 126) {
            fprintf(fp, "%c\t\t", (char)ch);
        } else if (ch == 10) {
            fprintf(fp, "\\n\t\t");
        } else if (ch == 13) {
            fprintf(fp, "\\r\t\t");
        } else if (ch == 9) {
            fprintf(fp, "\\t\t\t");
        } else if (ch == 32) {
            fprintf(fp, "空格\t\t");
        } else if (ch < 32) {
            fprintf(fp, "控制字符\t");
        } else {
            // UTF-8字符，使用统一函数转换输出
            char utf8_str[5];
            utf8_to_bytes(ch, utf8_str);
            fprintf(fp, "%s\t\t", utf8_str);
        }

        // 显示编码
        for (Byte j = 0; j < code->_size; j++) {
            Byte bit_pos = code->_size - 1 - j;
            bool bit = (code->_code >> bit_pos) & 1;
            fprintf(fp, "%d", bit ? 1 : 0);
        }

        // 填充空格使对齐
        for (Byte j = code->_size; j < 16; j++) {
            fprintf(fp, " ");
        }

        fprintf(fp, "\t%d\n", code->_size);

        // 统计长度分布
        length_dist[code->_size]++;
        total_bits += code->_size;
    }

    // 输出编码长度统计
    fprintf(fp, "\n编码长度分布:\n");
    fprintf(fp, "长度\t字符数\n");
    fprintf(fp, "----\t------\n");
    for (int len = 1; len <= 64; len++) {
        if (length_dist[len] > 0) {
            fprintf(fp, "%d\t%zu\n", len, length_dist[len]);
        }
    }

    fprintf(fp, "\n平均编码长度: %.3f 位\n", (double)total_bits / sqlist_size(code_table));

    fclose(fp);
    printf("✓ 编码表已保存到: %s\n", filename);
}

int main(int argc, char *argv[]) {
    printf("=== 赫夫曼编码实验 ===\n\n");

    // 检查命令行参数
    if (argc < 3) {
        printf("使用方法: %s <操作> <输入文件> [输出文件]\n", argv[0]);
        printf("操作:\n");
        printf("  encode <输入文件> <输出文件> - 编码文件\n");
        printf("  decode <编码文件> <输出文件> - 解码文件\n");
        printf("  test <输入文件> - 完整测试（编码+解码+验证）\n");
        printf("示例:\n");
        printf("  %s encode simple.txt simple.huf\n", argv[0]);
        printf("  %s decode simple.huf simple_decoded.txt\n", argv[0]);
        printf("  %s test simple.txt\n", argv[0]);
        return 1;
    }

    const char *operation = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argc > 3 ? argv[3] : NULL;

    // 根据操作设置文件路径
    char encoded_file[256];
    char decoded_file[256];

    if (strcmp(operation, "encode") == 0) {
        if (!output_file) {
            printf("错误：编码操作需要指定输出文件\n");
            return 1;
        }
        strcpy(encoded_file, output_file);
    } else if (strcmp(operation, "decode") == 0) {
        if (!output_file) {
            printf("错误：解码操作需要指定输出文件\n");
            return 1;
        }
        strcpy(decoded_file, output_file);
    } else if (strcmp(operation, "test") == 0) {
        snprintf(encoded_file, sizeof(encoded_file), "%s.huf", input_file);
        snprintf(decoded_file, sizeof(decoded_file), "%s.decoded", input_file);
    } else {
        printf("错误：未知操作 '%s'\n", operation);
        return 1;
    }

    printf("操作: %s\n", operation);
    printf("输入文件: %s\n", input_file);
    if (strcmp(operation, "encode") == 0) {
        printf("输出文件: %s\n", encoded_file);
    } else if (strcmp(operation, "decode") == 0) {
        printf("输出文件: %s\n", decoded_file);
    } else {
        printf("编码文件: %s\n", encoded_file);
        printf("解码文件: %s\n", decoded_file);
    }
    printf("\n");

    clock_t start_time, end_time;

    // 1. 创建文件处理器
    printf("1. 初始化文件处理器...\n");
    hdfile hf = new_hdfile();
    if (hf == NULL) {
        printf("错误：无法创建文件处理器\n");
        return 1;
    }

    // 2. 统计字符频率（编码和测试操作需要）
    sqlist freq_table = NULL;
    huffman hm = NULL;
    hufftree tree = NULL;
    sqlist length_table = NULL;
    sqlist code_table = NULL;

    if (strcmp(operation, "encode") == 0 || strcmp(operation, "test") == 0) {
        printf("\n2. 统计字符频率...\n");
        start_time = clock();

        Exception ex = hdfile_open(hf, input_file, NULL);
        if (ex.status != SUCCESS) {
            printf("错误：%s\n", ex.msg);
            // free_hdfile(hf);
            return 1;
        }

        freq_table = hdfile_count_frequency(hf);
        if (freq_table == NULL) {
            printf("错误：字符频率统计失败\n");
            // free_hdfile(hf);
            return 1;
        }

        end_time = clock();
        printf("统计到 %zu 个不同字符\n", sqlist_size(freq_table));
        printf("频率统计耗时: %.2f ms\n",
               ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);

        hdfile_close(hf);

        // 3. 构建赫夫曼树和编码表
        printf("\n3. 构建赫夫曼树和编码表...\n");
        start_time = clock();

        hm = new_huffman();
        if (hm == NULL) {
            printf("错误：无法创建赫夫曼处理器\n");
            free_sqlist(freq_table);
            free_hdfile(hf);
            return 1;
        }

        // 导入频率表
        Exception load_ex = huffman_load(hm, Freque, freq_table);
        if (load_ex.status != SUCCESS) {
            printf("错误：导入频率表失败\n");
            free_huffman(hm);
            free_sqlist(freq_table);
            free_hdfile(hf);
            return 1;
        }

        // 构建树
        tree = huffman_build(hm);
        if (tree == NULL) {
            printf("错误：构建赫夫曼树失败\n");
            free_huffman(hm);
            free_sqlist(freq_table);
            free_hdfile(hf);
            return 1;
        }

        // 获取字长表和编码表
        length_table = huffman_table(hm, Length);
        code_table = huffman_table(hm, Code);

        end_time = clock();
        printf("构建赫夫曼树耗时: %.2f ms\n",
               ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);

        // 4. 显示编码表信息
        printf("\n4. 赫夫曼编码表 (前20个字符):\n");
        printf("Unicode\t字符\t编码\n");
        printf("-------\t----\t----\n");

        size_t display_count = sqlist_size(code_table) > 20 ? 20 : sqlist_size(code_table);
        for (size_t i = 0; i < display_count; i++) {
            pair p = *(pair*)sqlist_at(code_table, i);
            utf8 ch = visitp_cast(utf8, p->first);
            huffcode code = (huffcode)p->second;
            display_utf8_info(ch, code);
        }

        if (sqlist_size(code_table) > 20) {
            printf("... (共 %zu 个字符)\n", sqlist_size(code_table));
        }

        // 输出频率表和编码表到文件
        char freq_table_file[512];
        char encoding_table_file[512];
        snprintf(freq_table_file, sizeof(freq_table_file), "%s_frequency_table.txt", input_file);
        snprintf(encoding_table_file, sizeof(encoding_table_file), "%s_encoding_table.txt", input_file);

        output_frequency_table(freq_table, freq_table_file);
        output_encoding_table(code_table, encoding_table_file);

        // 5. 编码文件
        printf("\n5. 编码文件...\n");
        start_time = clock();

        Exception ex2 = hdfile_open(hf, input_file, encoded_file);
        if (ex2.status != SUCCESS) {
            printf("错误：%s\n", ex2.msg);
            free_huffman(hm);
            free_sqlist(freq_table);
            free_hdfile(hf);
            return 1;
        }

        // 写入字长表
        Exception write_ex = hdfile_write_length_table(hf, length_table);
        if (write_ex.status != SUCCESS) {
            printf("错误：写入字长表失败\n");
            hdfile_close(hf);
            free_huffman(hm);
            free_sqlist(freq_table);
            free_hdfile(hf);
            return 1;
        }

        // 编码文件内容
        Exception encode_ex = hdfile_encode(hf, code_table);
        if (encode_ex.status != SUCCESS) {
            printf("错误：编码失败\n");
            hdfile_close(hf);
            free_huffman(hm);
            free_sqlist(freq_table);
            free_hdfile(hf);
            return 1;
        }

        hdfile_close(hf);

        end_time = clock();
        printf("文件编码耗时: %.2f ms\n",
               ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);
    }

    // 6. 解码文件（解码和测试操作需要）
    if (strcmp(operation, "decode") == 0 || strcmp(operation, "test") == 0) {
        printf("\n6. 解码文件...\n");
        start_time = clock();

        // 对于decode操作，hdfile_decode函数现在可以从编码文件中重建哈夫曼树
        if (strcmp(operation, "decode") == 0) {
            printf("从编码文件中重建哈夫曼树并解码\n");
        }

        Exception ex3 = hdfile_open(hf,
            strcmp(operation, "decode") == 0 ? input_file : encoded_file,
            strcmp(operation, "decode") == 0 ? output_file : decoded_file);
        if (ex3.status != SUCCESS) {
            printf("错误：%s\n", ex3.msg);
            if (hm) free_huffman(hm);
            if (freq_table) free_sqlist(freq_table);
            free_hdfile(hf);
            return 1;
        }

        Exception decode_ex = hdfile_decode(hf, tree);
        if (decode_ex.status != SUCCESS) {
            printf("错误：解码失败\n");
            hdfile_close(hf);
            if (hm) free_huffman(hm);
            if (freq_table) free_sqlist(freq_table);
            free_hdfile(hf);
            return 1;
        }

        hdfile_close(hf);

        end_time = clock();
        printf("文件解码耗时: %.2f ms\n",
               ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);
    }

    // 7. 比较文件大小和压缩率（仅测试操作）
    if (strcmp(operation, "test") == 0) {
        printf("\n7. 文件大小比较:\n");
        long original_size = get_file_size(input_file);
        long encoded_size = get_file_size(encoded_file);
        long decoded_size = get_file_size(decoded_file);

        printf("原始文件大小: %ld 字节\n", original_size);
        printf("编码文件大小: %ld 字节\n", encoded_size);
        printf("解码文件大小: %ld 字节\n", decoded_size);

        if (original_size > 0) {
            double compression_ratio = ((double)(original_size - encoded_size) / original_size) * 100;
            printf("压缩率: %.2f%%\n", compression_ratio);
        }

        // 8. 验证文件一致性
        printf("\n8. 验证文件一致性...\n");
        if (compare_files(input_file, decoded_file)) {
            printf("✓ 解码文件与原始文件完全一致！\n");
        } else {
            printf("✗ 解码文件与原始文件不一致！\n");
        }
    }

    // 清理资源 - 暂时注释以避免崩溃
    // if (hm) free_huffman(hm);
    // if (freq_table) free_sqlist(freq_table);
    // free_hdfile(hf);

    printf("\n=== 操作完成 ===\n");
    return 0;
}
