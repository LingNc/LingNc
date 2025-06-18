#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../include/huffman.h"
#include "../include/hdfile.h"
#include "../include/tools.h"

// Test function to check total_bits value
void test_total_bits() {
    printf("=== 测试total_bits值 ===\n");
    
    // Use our boundary test file
    const char* test_filename = "testdata/boundary_test.txt";
    const char* encoded_filename = "testdata/boundary_test.huf";
    
    // Step 1: Check if files exist
    FILE* test_check = fopen(test_filename, "rb");
    if (test_check == NULL) {
        printf("ERROR: 测试文件不存在\n");
        return;
    }
    fclose(test_check);
    
    FILE* encoded_check = fopen(encoded_filename, "rb");
    if (encoded_check == NULL) {
        printf("ERROR: 编码文件不存在\n");
        return;
    }
    fclose(encoded_check);
    
    // Step 2: Read total_bits from encoded file
    printf("步骤1: 从编码文件读取total_bits...\n");
    
    FILE* encoded_file = fopen(encoded_filename, "rb");
    fseek(encoded_file, -sizeof(size_t), SEEK_END);
    size_t stored_total_bits;
    fread(&stored_total_bits, sizeof(size_t), 1, encoded_file);
    fclose(encoded_file);
    
    printf("存储的total_bits: %zu\n", stored_total_bits);
    
    // Step 3: Calculate expected bits manually
    printf("\n步骤2: 手动计算预期的位数...\n");
    
    // Read the original file size
    FILE* orig_file = fopen(test_filename, "rb");
    fseek(orig_file, 0, SEEK_END);
    long file_size = ftell(orig_file);
    fclose(orig_file);
    
    printf("原文件大小: %ld 字节\n", file_size);
    
    // Get frequency and build encoding table
    hdfile hf = new_hdfile();
    hdfile_open(hf, test_filename, NULL);
    sqlist freq_table = hdfile_count_frequency(hf);
    hdfile_close(hf);
    
    printf("字符种类: %zu\n", sqlist_size(freq_table));
    
    // Build huffman tree and code table
    huffman hm = new_huffman();
    huffman_load(hm, Freque, freq_table);
    hufftree tree = huffman_build(hm);
    sqlist code_table = huffman_table(hm, Code);
    
    // Calculate total bits manually
    size_t calculated_total_bits = 0;
    
    printf("\n字符编码分析:\n");
    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair freq_p = *(pair*)sqlist_at(freq_table, i);
        pair code_p = *(pair*)sqlist_at(code_table, i);
        
        utf8 ch = *(utf8*)freq_p->first;
        size_t freq = *(size_t*)freq_p->second;
        huffcode code = (huffcode)code_p->second;
        
        size_t char_bits = freq * code->_size;
        calculated_total_bits += char_bits;
        
        printf("  字符 U+%04X: 频率 %zu × 长度 %u = %zu 位\n", 
               (unsigned int)ch, freq, code->_size, char_bits);
    }
    
    printf("\n计算的total_bits: %zu\n", calculated_total_bits);
    printf("存储的total_bits: %zu\n", stored_total_bits);
    
    if (calculated_total_bits == stored_total_bits) {
        printf("✓ total_bits值正确\n");
    } else {
        printf("✗ total_bits值不匹配！\n");
    }
    
    // Step 4: Test decoding with debug info
    printf("\n步骤3: 测试解码过程...\n");
    
    hdfile decoder = new_hdfile();
    hdfile_open(decoder, encoded_filename, "testdata/boundary_debug_decoded.txt");
    
    // Read length table to skip it
    sqlist length_table = hdfile_read_length_table(decoder);
    printf("读取字长表成功，字符数: %zu\n", sqlist_size(length_table));
    
    // Read total_bits again
    fseek(decoder->_indata, -sizeof(size_t), SEEK_END);
    size_t decode_total_bits;
    fread(&decode_total_bits, sizeof(size_t), 1, decoder->_indata);
    printf("解码时读取的total_bits: %zu\n", decode_total_bits);
    
    // Get current position (start of encoded data)
    hdfile_close(decoder);
    hdfile_open(decoder, encoded_filename, "testdata/boundary_debug_decoded.txt");
    
    // Skip length table again to get to data start
    sqlist temp_table = hdfile_read_length_table(decoder);
    free_sqlist(temp_table);
    
    long data_start_pos = ftell(decoder->_indata);
    
    // Get file size to calculate data size
    fseek(decoder->_indata, 0, SEEK_END);
    long encoded_file_size = ftell(decoder->_indata);
    
    long data_size_bytes = encoded_file_size - data_start_pos - sizeof(size_t);
    size_t data_size_bits = data_size_bytes * 8;
    
    printf("编码数据起始位置: %ld\n", data_start_pos);
    printf("编码文件总大小: %ld 字节\n", encoded_file_size);
    printf("编码数据大小: %ld 字节 = %zu 位\n", data_size_bytes, data_size_bits);
    printf("有效编码位数: %zu\n", decode_total_bits);
    
    if (decode_total_bits > data_size_bits) {
        printf("✗ 错误：total_bits (%zu) 超过了可用数据位数 (%zu)\n", 
               decode_total_bits, data_size_bits);
    } else {
        printf("✓ total_bits在合理范围内\n");
    }
    
    hdfile_close(decoder);
    free_huffman(hm);
    free_hdfile(hf);
    free_hdfile(decoder);
    
    printf("\n=== 测试完成 ===\n");
}

int main() {
    test_total_bits();
    return 0;
}
