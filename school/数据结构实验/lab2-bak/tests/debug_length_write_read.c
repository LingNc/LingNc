#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../include/huffman.h"
#include "../include/hdfile.h"
#include "../include/tools.h"

void test_length_table_write_read() {
    printf("=== 测试字长表写入和读取的具体细节 ===\n");
    
    const char* test_filename = "testdata/length_debug.txt";
    const char* encoded_filename = "testdata/length_debug.huf";
    
    // 创建简单测试文件
    FILE* test_file = fopen(test_filename, "w");
    fprintf(test_file, "aaée");
    fclose(test_file);
    
    // 编码过程
    hdfile encoder = new_hdfile();
    hdfile_open(encoder, test_filename, encoded_filename);
    sqlist freq_table = hdfile_count_frequency(encoder);
    
    printf("频率表大小: %zu\n", sqlist_size(freq_table));
    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t freq = *(size_t*)p->second;
        printf("  字符 U+%04X: 频率 %zu\n", (unsigned int)ch, freq);
    }
    
    huffman hm = new_huffman();
    huffman_load(hm, Freque, freq_table);
    hufftree tree = huffman_build(hm);
    sqlist length_table = huffman_table(hm, Length);
    
    printf("\n字长表大小: %zu\n", sqlist_size(length_table));
    for (size_t i = 0; i < sqlist_size(length_table); i++) {
        pair p = *(pair*)sqlist_at(length_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t length = *(size_t*)p->second;
        printf("  字符 U+%04X: 长度 %zu\n", (unsigned int)ch, length);
    }
    
    hdfile_close(encoder);
    hdfile_open(encoder, test_filename, encoded_filename);
    
    // 写入字长表
    printf("\n写入字长表...\n");
    Exception write_ex = hdfile_write_length_table(encoder, length_table);
    if (write_ex.status != SUCCESS) {
        printf("ERROR: 写入失败: %s\n", write_ex.msg);
        return;
    }
    printf("✓ 字长表写入成功\n");
    
    // 检查文件位置
    long pos_after_write = ftell(encoder->_outdata);
    printf("写入后文件位置: %ld\n", pos_after_write);
    
    // 写入一些编码数据（模拟）
    sqlist code_table = huffman_table(hm, Code);
    Exception encode_ex = hdfile_encode(encoder, code_table);
    if (encode_ex.status != SUCCESS) {
        printf("ERROR: 编码失败: %s\n", encode_ex.msg);
        return;
    }
    
    long pos_after_encode = ftell(encoder->_outdata);
    printf("编码后文件位置: %ld\n", pos_after_encode);
    
    hdfile_close(encoder);
    
    // 现在测试读取
    printf("\n测试读取字长表...\n");
    hdfile decoder = new_hdfile();
    hdfile_open(decoder, encoded_filename, NULL);
    
    // 检查文件开头的原始字节
    rewind(decoder->_indata);
    unsigned char header_bytes[20];
    size_t read_count = fread(header_bytes, 1, 20, decoder->_indata);
    printf("文件开头 %zu 字节: ", read_count);
    for (size_t i = 0; i < read_count; i++) {
        printf("%02X ", header_bytes[i]);
    }
    printf("\n");
    
    // 手动解析table_size
    rewind(decoder->_indata);
    uint32_t raw_table_size;
    fread(&raw_table_size, sizeof(uint32_t), 1, decoder->_indata);
    printf("原始table_size读取: %u (0x%08X)\n", raw_table_size, raw_table_size);
    
    // 重置并使用函数读取
    rewind(decoder->_indata);
    sqlist read_length_table = hdfile_read_length_table(decoder);
    
    if (read_length_table == NULL) {
        printf("ERROR: 读取字长表失败\n");
        hdfile_close(decoder);
        free_hdfile(decoder);
        return;
    }
    
    printf("读取的字长表大小: %zu\n", sqlist_size(read_length_table));
    
    // 显示读取结果的前几个
    size_t display_count = sqlist_size(read_length_table) > 10 ? 10 : sqlist_size(read_length_table);
    for (size_t i = 0; i < display_count; i++) {
        pair p = *(pair*)sqlist_at(read_length_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t length = *(size_t*)p->second;
        printf("  [%zu] 字符 U+%04X: 长度 %zu\n", i, (unsigned int)ch, length);
    }
    
    // 检查读取后的文件位置
    long pos_after_read = ftell(decoder->_indata);
    printf("读取后文件位置: %ld\n", pos_after_read);
    
    hdfile_close(decoder);
    free_hdfile(encoder);
    free_hdfile(decoder);
    free_huffman(hm);
    
    printf("\n=== 测试完成 ===\n");
}

int main() {
    test_length_table_write_read();
    return 0;
}
