#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../include/huffman.h"
#include "../include/hdfile.h"
#include "../include/tools.h"

// Test function to debug actual file encoding/decoding process
void test_file_encode_decode() {
    printf("=== 测试文件编码解码过程中的Unicode值 ===\n");

    // Create a test file with the problematic character 'é'
    const char* test_filename = "testdata/unicode_test.txt";
    const char* encoded_filename = "testdata/unicode_test.huf";
    const char* decoded_filename = "testdata/unicode_test_decoded.txt";

    // Step 1: Create test file with UTF-8 content
    printf("步骤1: 创建包含'é'字符的测试文件...\n");
    FILE* test_file = fopen(test_filename, "w");
    if (test_file == NULL) {
        printf("ERROR: 无法创建测试文件\n");
        return;
    }

    // Write UTF-8 bytes for 'é' (U+00E9) = 0xC3 0xA9
    // Also include some ASCII characters for context
    const char* test_content = "aé ";  // a + é + space
    fwrite(test_content, 1, strlen(test_content), test_file);
    fclose(test_file);
    printf("✓ 测试文件创建成功，内容: \"%s\"\n", test_content);

    // Step 2: Encode the file
    printf("\n步骤2: 编码测试文件...\n");
    hdfile encoder = new_hdfile();
    if (encoder == NULL) {
        printf("ERROR: 无法创建编码器\n");
        return;
    }

    Exception ex = hdfile_open(encoder, test_filename, encoded_filename);
    if (ex.status != SUCCESS) {
        printf("ERROR: 打开文件失败: %s\n", ex.msg);
        return;
    }

    // Get frequency table
    sqlist freq_table = hdfile_count_frequency(encoder);
    if (freq_table == NULL) {
        printf("ERROR: 无法统计频率\n");
        hdfile_close(encoder);
        free_hdfile(encoder);
        return;
    }

    printf("频率统计结果:\n");
    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t freq = *(size_t*)p->second;
        printf("  字符 U+%04X (十进制: %lu): 频率 %zu\n", (unsigned int)ch, ch, freq);
    }

    // Build Huffman tree and get code table
    huffman hm = new_huffman();
    huffman_load(hm, Freque, freq_table);
    huffman_build(hm);  // Build tree but don't store it
    sqlist code_table = huffman_table(hm, Code);

    printf("\n编码表:\n");
    for (size_t i = 0; i < sqlist_size(code_table); i++) {
        pair p = *(pair*)sqlist_at(code_table, i);
        utf8 ch = *(utf8*)p->first;
        huffcode code = (huffcode)p->second;
        printf("  字符 U+%04X: 编码 ", (unsigned int)ch);
        for (int j = code->_size - 1; j >= 0; j--) {
            bool bit = (code->_code >> j) & 1;
            printf("%d", bit ? 1 : 0);
        }
        printf(" (长度: %u)\n", code->_size);
    }

    hdfile_close(encoder);

    // Reopen for encoding
    ex = hdfile_open(encoder, test_filename, encoded_filename);
    if (ex.status != SUCCESS) {
        printf("ERROR: 重新打开文件失败: %s\n", ex.msg);
        return;
    }

    ex = hdfile_encode(encoder, code_table);
    if (ex.status != SUCCESS) {
        printf("ERROR: 编码失败: %s\n", ex.msg);
        hdfile_close(encoder);
        free_hdfile(encoder);
        return;
    }
    printf("✓ 文件编码成功\n");
    hdfile_close(encoder);

    // Step 3: Decode the file
    printf("\n步骤3: 解码文件...\n");

    hdfile decoder = new_hdfile();
    if (decoder == NULL) {
        printf("ERROR: 无法创建解码器\n");
        free_hdfile(encoder);
        return;
    }

    ex = hdfile_open(decoder, encoded_filename, decoded_filename);
    if (ex.status != SUCCESS) {
        printf("ERROR: 打开解码文件失败: %s\n", ex.msg);
        free_hdfile(encoder);
        free_hdfile(decoder);
        return;
    }

    // Read the length table from the encoded file
    sqlist length_table = hdfile_read_length_table(decoder);
    if (length_table == NULL) {
        printf("ERROR: 无法读取字长表\n");
        hdfile_close(decoder);
        free_hdfile(encoder);
        free_hdfile(decoder);
        return;
    }

    printf("从文件读取的字长表:\n");
    for (size_t i = 0; i < sqlist_size(length_table); i++) {
        pair p = *(pair*)sqlist_at(length_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t length = *(size_t*)p->second;

        printf("  字符: U+%04X (十进制: %lu)", (unsigned int)ch, ch);
        if (ch >= 32 && ch <= 126) {
            printf(" ['%c']", (char)ch);
        } else if (ch == 0x00E9) {
            printf(" ['é']");
        }
        printf(", 字长: %zu\n", length);
    }

    // Build Huffman tree from length table for decoding
    huffman decode_hm = new_huffman();
    huffman_load(decode_hm, Length, length_table);
    hufftree decode_tree = huffman_build(decode_hm);

    if (decode_tree == NULL) {
        printf("ERROR: 无法构建解码树\n");
        hdfile_close(decoder);
        free_huffman(hm);
        free_huffman(decode_hm);
        free_hdfile(encoder);
        free_hdfile(decoder);
        return;
    }

    printf("✓ 解码树构建成功\n");

    // Perform the actual decoding
    hdfile_close(decoder);
    ex = hdfile_open(decoder, encoded_filename, decoded_filename);
    if (ex.status != SUCCESS) {
        printf("ERROR: 重新打开解码文件失败: %s\n", ex.msg);
        return;
    }

    ex = hdfile_decode(decoder, decode_tree);
    if (ex.status != SUCCESS) {
        printf("ERROR: 解码失败: %s\n", ex.msg);
        hdfile_close(decoder);
        free_huffman(hm);
        free_huffman(decode_hm);
        free_hdfile(encoder);
        free_hdfile(decoder);
        return;
    }
    printf("✓ 文件解码成功\n");
    hdfile_close(decoder);

    // Step 4: Compare original and decoded files
    printf("\n步骤4: 比较原文件和解码文件...\n");

    // Read original file
    FILE* orig_file = fopen(test_filename, "rb");
    if (orig_file == NULL) {
        printf("ERROR: 无法打开原文件\n");
        free_huffman(hm);
        free_huffman(decode_hm);
        free_hdfile(encoder);
        free_hdfile(decoder);
        return;
    }

    fseek(orig_file, 0, SEEK_END);
    long orig_size = ftell(orig_file);
    fseek(orig_file, 0, SEEK_SET);

    unsigned char* orig_content = malloc(orig_size);
    fread(orig_content, 1, orig_size, orig_file);
    fclose(orig_file);

    // Read decoded file
    FILE* decoded_file = fopen(decoded_filename, "rb");
    if (decoded_file == NULL) {
        printf("ERROR: 无法打开解码文件\n");
        free(orig_content);
        return;
    }

    fseek(decoded_file, 0, SEEK_END);
    long decoded_size = ftell(decoded_file);
    fseek(decoded_file, 0, SEEK_SET);

    unsigned char* decoded_content = malloc(decoded_size);
    fread(decoded_content, 1, decoded_size, decoded_file);
    fclose(decoded_file);

    printf("原文件大小: %ld 字节\n", orig_size);
    printf("解码文件大小: %ld 字节\n", decoded_size);

    printf("\n原文件内容 (十六进制):\n");
    for (long i = 0; i < orig_size; i++) {
        printf("%02X ", orig_content[i]);
    }
    printf("\n");

    printf("解码文件内容 (十六进制):\n");
    for (long i = 0; i < decoded_size; i++) {
        printf("%02X ", decoded_content[i]);
    }
    printf("\n");

    // Compare byte by byte
    printf("\n字节比较:\n");
    long min_size = orig_size < decoded_size ? orig_size : decoded_size;
    bool files_match = true;

    for (long i = 0; i < min_size; i++) {
        if (orig_content[i] != decoded_content[i]) {
            printf("差异在位置 %ld: 原文件=0x%02X, 解码文件=0x%02X\n",
                   i, orig_content[i], decoded_content[i]);
            files_match = false;
        }
    }

    if (orig_size != decoded_size) {
        printf("文件大小不匹配!\n");
        files_match = false;
    }

    if (files_match) {
        printf("✓ 文件完全匹配\n");
    } else {
        printf("✗ 文件不匹配，存在UTF-8解码问题\n");

        // Analyze UTF-8 decoding specifically
        printf("\nUTF-8解码分析:\n");
        printf("查找'é'字符 (应该是 0xC3 0xA9):\n");

        for (long i = 0; i < orig_size - 1; i++) {
            if (orig_content[i] == 0xC3 && orig_content[i+1] == 0xA9) {
                printf("原文件位置 %ld-%ld: 找到'é' (0xC3 0xA9)\n", i, i+1);

                if (i+1 < decoded_size) {
                    printf("解码文件位置 %ld-%ld: 0x%02X 0x%02X",
                           i, i+1, decoded_content[i], decoded_content[i+1]);
                    if (decoded_content[i] == 0xEF && decoded_content[i+1] == 0xBF) {
                        printf(" (替换字符的开始)\n");
                    } else {
                        printf("\n");
                    }
                }
                break;
            }
        }
    }

    // Cleanup
    free(orig_content);
    free(decoded_content);
    free_hdfile(encoder);
    free_hdfile(decoder);

    printf("\n=== 测试完成 ===\n");
}

int main() {
    test_file_encode_decode();
    return 0;
}
