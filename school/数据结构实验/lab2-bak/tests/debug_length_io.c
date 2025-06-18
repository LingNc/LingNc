#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../include/huffman.h"
#include "../include/hdfile.h"
#include "../include/tools.h"

// Test function to debug length table writing/reading
void test_length_table_io() {
    printf("=== 测试字长表写入/读取 ===\n");
    
    // Create test files
    const char* test_filename = "testdata/length_test.txt";
    const char* encoded_filename = "testdata/length_test.huf";
    
    // Step 1: Create simple test file
    printf("步骤1: 创建测试文件...\n");
    FILE* test_file = fopen(test_filename, "w");
    if (test_file == NULL) {
        printf("ERROR: 无法创建测试文件\n");
        return;
    }
    
    const char* test_content = "aé";  // Simple content with 'é'
    fwrite(test_content, 1, strlen(test_content), test_file);
    fclose(test_file);
    printf("✓ 测试文件创建成功，内容: \"%s\"\n", test_content);
    
    // Step 2: Count frequency and build Huffman components
    printf("\n步骤2: 统计频率并构建霍夫曼编码...\n");
    hdfile encoder = new_hdfile();
    Exception ex = hdfile_open(encoder, test_filename, encoded_filename);
    if (ex.status != SUCCESS) {
        printf("ERROR: 打开文件失败: %s\n", ex.msg);
        return;
    }
    
    sqlist freq_table = hdfile_count_frequency(encoder);
    if (freq_table == NULL) {
        printf("ERROR: 频率统计失败\n");
        hdfile_close(encoder);
        free_hdfile(encoder);
        return;
    }
    
    printf("频率表:\n");
    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t freq = *(size_t*)p->second;
        printf("  字符 U+%04X (十进制: %lu): 频率 %zu\n", (unsigned int)ch, ch, freq);
    }
    
    huffman hm = new_huffman();
    huffman_load(hm, Freque, freq_table);
    huffman_build(hm);
    
    // Get length table
    sqlist length_table = huffman_table(hm, Length);
    if (length_table == NULL) {
        printf("ERROR: 无法获取字长表\n");
        hdfile_close(encoder);
        free_hdfile(encoder);
        free_huffman(hm);
        return;
    }
    
    printf("\n字长表:\n");
    for (size_t i = 0; i < sqlist_size(length_table); i++) {
        pair p = *(pair*)sqlist_at(length_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t length = *(size_t*)p->second;
        printf("  字符 U+%04X (十进制: %lu): 字长 %zu\n", (unsigned int)ch, ch, length);
    }
    
    hdfile_close(encoder);
    
    // Step 3: Write length table to file
    printf("\n步骤3: 写入字长表到文件...\n");
    ex = hdfile_open(encoder, test_filename, encoded_filename);
    if (ex.status != SUCCESS) {
        printf("ERROR: 重新打开文件失败: %s\n", ex.msg);
        free_hdfile(encoder);
        free_huffman(hm);
        return;
    }
    
    ex = hdfile_write_length_table(encoder, length_table);
    if (ex.status != SUCCESS) {
        printf("ERROR: 写入字长表失败: %s\n", ex.msg);
        hdfile_close(encoder);
        free_hdfile(encoder);
        free_huffman(hm);
        return;
    }
    printf("✓ 字长表写入成功\n");
    
    hdfile_close(encoder);
    
    // Step 4: Read length table from file
    printf("\n步骤4: 从文件读取字长表...\n");
    hdfile decoder = new_hdfile();
    ex = hdfile_open(decoder, encoded_filename, "dummy_output.txt");
    if (ex.status != SUCCESS) {
        printf("ERROR: 打开编码文件失败: %s\n", ex.msg);
        free_hdfile(encoder);
        free_hdfile(decoder);
        free_huffman(hm);
        return;
    }
    
    sqlist read_length_table = hdfile_read_length_table(decoder);
    if (read_length_table == NULL) {
        printf("ERROR: 读取字长表失败\n");
        hdfile_close(decoder);
        free_hdfile(encoder);
        free_hdfile(decoder);
        free_huffman(hm);
        return;
    }
    printf("✓ 字长表读取成功\n");
    
    printf("\n读取的字长表:\n");
    for (size_t i = 0; i < sqlist_size(read_length_table); i++) {
        pair p = *(pair*)sqlist_at(read_length_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t length = *(size_t*)p->second;
        printf("  字符 U+%04X (十进制: %lu): 字长 %zu\n", (unsigned int)ch, ch, length);
    }
    
    // Step 5: Compare original and read length tables
    printf("\n步骤5: 比较原始和读取的字长表...\n");
    
    if (sqlist_size(length_table) != sqlist_size(read_length_table)) {
        printf("✗ 字长表大小不匹配: 原始 %zu vs 读取 %zu\n", 
               sqlist_size(length_table), sqlist_size(read_length_table));
    } else {
        bool tables_match = true;
        for (size_t i = 0; i < sqlist_size(length_table); i++) {
            pair orig_p = *(pair*)sqlist_at(length_table, i);
            pair read_p = *(pair*)sqlist_at(read_length_table, i);
            
            utf8 orig_ch = *(utf8*)orig_p->first;
            utf8 read_ch = *(utf8*)read_p->first;
            size_t orig_len = *(size_t*)orig_p->second;
            size_t read_len = *(size_t*)read_p->second;
            
            if (orig_ch != read_ch || orig_len != read_len) {
                printf("✗ 字长表项 %zu 不匹配:\n", i);
                printf("    原始: U+%04X, 长度 %zu\n", (unsigned int)orig_ch, orig_len);
                printf("    读取: U+%04X, 长度 %zu\n", (unsigned int)read_ch, read_len);
                tables_match = false;
            }
        }
        
        if (tables_match) {
            printf("✓ 字长表完全匹配\n");
        }
    }
    
    // Cleanup (don't worry about segment faults for now)
    hdfile_close(decoder);
    printf("\n=== 测试完成 ===\n");
}

int main() {
    test_length_table_io();
    return 0;
}
