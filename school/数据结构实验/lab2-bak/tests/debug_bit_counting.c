#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../include/huffman.h"
#include "../include/hdfile.h"
#include "../include/tools.h"

// Test function to debug bit counting during encoding
void debug_bit_counting() {
    printf("=== 调试编码过程中的位计数 ===\n");
    
    const char* test_filename = "testdata/bit_debug.txt";
    const char* encoded_filename = "testdata/bit_debug.huf";
    
    // 创建一个简单的测试文件
    printf("步骤1: 创建测试文件...\n");
    FILE* test_file = fopen(test_filename, "wb");
    if (test_file == NULL) {
        printf("ERROR: 无法创建测试文件\n");
        return;
    }
    
    // 写入: "aabé" - 这样'a'会有高频率，'é'会有较长编码
    fprintf(test_file, "aabé");
    fclose(test_file);
    
    // 获取文件大小
    test_file = fopen(test_filename, "rb");
    fseek(test_file, 0, SEEK_END);
    long orig_size = ftell(test_file);
    fclose(test_file);
    
    printf("✓ 测试文件创建成功，大小: %ld 字节\n", orig_size);
    
    // 编码文件
    printf("\n步骤2: 编码文件...\n");
    hdfile encoder = new_hdfile();
    Exception ex = hdfile_open(encoder, test_filename, encoded_filename);
    if (ex.status != SUCCESS) {
        printf("ERROR: 打开文件失败: %s\n", ex.msg);
        return;
    }
    
    // 统计频率
    sqlist freq_table = hdfile_count_frequency(encoder);
    printf("频率统计:\n");
    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t freq = *(size_t*)p->second;
        printf("  字符 U+%04X (十进制: %lu): 频率 %zu\n", (unsigned int)ch, ch, freq);
    }
    
    // 构建编码表
    huffman hm = new_huffman();
    huffman_load(hm, Freque, freq_table);
    hufftree tree = huffman_build(hm);
    sqlist code_table = huffman_table(hm, Code);
    
    printf("\n编码表:\n");
    size_t manual_total_bits = 0;
    for (size_t i = 0; i < sqlist_size(code_table); i++) {
        pair p = *(pair*)sqlist_at(code_table, i);
        utf8 ch = *(utf8*)p->first;
        huffcode code = (huffcode)p->second;
        
        // 找到对应的频率
        size_t freq = 0;
        for (size_t j = 0; j < sqlist_size(freq_table); j++) {
            pair fp = *(pair*)sqlist_at(freq_table, j);
            if (*(utf8*)fp->first == ch) {
                freq = *(size_t*)fp->second;
                break;
            }
        }
        
        printf("  字符 U+%04X: 编码 ", (unsigned int)ch);
        for (int j = code->_size - 1; j >= 0; j--) {
            bool bit = (code->_code >> j) & 1;
            printf("%d", bit ? 1 : 0);
        }
        printf(" (长度: %u, 频率: %zu, 总位数: %u)\n", code->_size, freq, code->_size * (unsigned int)freq);
        
        manual_total_bits += code->_size * freq;
    }
    
    printf("手动计算的总位数: %zu\n", manual_total_bits);
    
    hdfile_close(encoder);
    ex = hdfile_open(encoder, test_filename, encoded_filename);
    if (ex.status != SUCCESS) {
        printf("ERROR: 重新打开文件失败: %s\n", ex.msg);
        return;
    }
    
    // 执行编码
    ex = hdfile_encode(encoder, code_table);
    if (ex.status != SUCCESS) {
        printf("ERROR: 编码失败: %s\n", ex.msg);
        hdfile_close(encoder);
        free_hdfile(encoder);
        return;
    }
    printf("✓ 文件编码成功\n");
    hdfile_close(encoder);
    
    // 分析编码文件
    printf("\n步骤3: 分析编码文件...\n");
    FILE* enc_file = fopen(encoded_filename, "rb");
    if (enc_file == NULL) {
        printf("ERROR: 无法打开编码文件\n");
        return;
    }
    
    fseek(enc_file, 0, SEEK_END);
    long enc_size = ftell(enc_file);
    printf("编码文件总大小: %ld 字节\n", enc_size);
    
    // 读取存储的total_bits
    fseek(enc_file, -sizeof(size_t), SEEK_END);
    size_t stored_total_bits;
    fread(&stored_total_bits, sizeof(size_t), 1, enc_file);
    printf("存储的total_bits: %zu\n", stored_total_bits);
    
    // 计算实际编码数据大小
    long header_size = enc_size - sizeof(size_t);
    
    // 跳过字长表，计算编码数据大小
    rewind(enc_file);
    
    // 读取字长表大小
    uint32_t length_table_size;
    fread(&length_table_size, sizeof(uint32_t), 1, enc_file);
    printf("字长表条目数: %u\n", length_table_size);
    
    // 跳过字长表数据
    long data_start = sizeof(uint32_t) + length_table_size * (sizeof(utf8) + sizeof(size_t));
    fseek(enc_file, data_start, SEEK_SET);
    
    long data_end = enc_size - sizeof(size_t);
    long encoded_data_bytes = data_end - data_start;
    long encoded_data_bits = encoded_data_bytes * 8;
    
    printf("字长表结束位置: %ld\n", data_start);
    printf("编码数据结束位置: %ld\n", data_end);
    printf("编码数据大小: %ld 字节 = %ld 位\n", encoded_data_bytes, encoded_data_bits);
    
    printf("\n比较:\n");
    printf("手动计算: %zu 位\n", manual_total_bits);
    printf("存储值:   %zu 位\n", stored_total_bits);
    printf("可用数据: %ld 位\n", encoded_data_bits);
    
    if (manual_total_bits == stored_total_bits) {
        printf("✓ 存储的total_bits正确\n");
    } else {
        printf("✗ 存储的total_bits不正确\n");
    }
    
    if (stored_total_bits <= encoded_data_bits) {
        printf("✓ 编码数据足够\n");
    } else {
        printf("✗ 编码数据不足，缺少 %zu 位\n", stored_total_bits - encoded_data_bits);
    }
    
    fclose(enc_file);
    
    // 清理资源
    free_huffman(hm);
    free_hdfile(encoder);
    
    printf("\n=== 调试完成 ===\n");
}

int main() {
    debug_bit_counting();
    return 0;
}
