#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../include/huffman.h"
#include "../include/hdfile.h"
#include "../include/tools.h"

// Test function to specifically test buffer boundary issues
void test_buffer_boundary() {
    printf("=== 测试缓冲区边界问题 ===\n");
    
    // 创建一个文件，其中'é'字符恰好跨越65536字节边界
    const char* test_filename = "testdata/boundary_test.txt";
    const char* encoded_filename = "testdata/boundary_test.huf";
    const char* decoded_filename = "testdata/boundary_test_decoded.txt";
    
    printf("步骤1: 创建边界测试文件...\n");
    FILE* test_file = fopen(test_filename, "wb");
    if (test_file == NULL) {
        printf("ERROR: 无法创建测试文件\n");
        return;
    }
    
    // 写入65534字节的'a'字符，然后写入'é'（2字节：c3 a9）
    // 这样'é'会跨越65536字节边界
    size_t buffer_size = 65536;
    size_t padding_size = buffer_size - 2;  // 留出2字节给'é'
    
    // 写入填充字符
    for (size_t i = 0; i < padding_size; i++) {
        fputc('a', test_file);
    }
    
    // 写入'é'字符的UTF-8编码：c3 a9
    unsigned char utf8_e[] = {0xc3, 0xa9};
    fwrite(utf8_e, 1, 2, test_file);
    
    // 再写入一些字符
    fprintf(test_file, "bcd");
    
    fclose(test_file);
    
    // 验证文件大小和内容
    test_file = fopen(test_filename, "rb");
    fseek(test_file, 0, SEEK_END);
    long file_size = ftell(test_file);
    fclose(test_file);
    
    printf("✓ 测试文件创建成功，大小: %ld 字节\n", file_size);
    printf("'é'字符位置: %zu-%zu (跨越%zu字节边界)\n", 
           padding_size, padding_size + 1, buffer_size);
    
    // 步骤2: 编码文件
    printf("\n步骤2: 编码文件...\n");
    hdfile encoder = new_hdfile();
    Exception ex = hdfile_open(encoder, test_filename, encoded_filename);
    if (ex.status != SUCCESS) {
        printf("ERROR: 打开文件失败: %s\n", ex.msg);
        return;
    }
    
    // 统计频率
    sqlist freq_table = hdfile_count_frequency(encoder);
    if (freq_table == NULL) {
        printf("ERROR: 频率统计失败\n");
        hdfile_close(encoder);
        free_hdfile(encoder);
        return;
    }
    
    printf("频率统计结果（前5个）:\n");
    size_t display_count = sqlist_size(freq_table) > 5 ? 5 : sqlist_size(freq_table);
    for (size_t i = 0; i < display_count; i++) {
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
    
    hdfile_close(encoder);
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
    
    // 步骤3: 解码文件
    printf("\n步骤3: 解码文件...\n");
    hdfile decoder = new_hdfile();
    ex = hdfile_open(decoder, encoded_filename, decoded_filename);
    if (ex.status != SUCCESS) {
        printf("ERROR: 打开解码文件失败: %s\n", ex.msg);
        free_hdfile(encoder);
        free_hdfile(decoder);
        return;
    }
    
    ex = hdfile_decode(decoder, tree);
    if (ex.status != SUCCESS) {
        printf("ERROR: 解码失败: %s\n", ex.msg);
        hdfile_close(decoder);
        free_huffman(hm);
        free_hdfile(encoder);
        free_hdfile(decoder);
        return;
    }
    printf("✓ 文件解码成功\n");
    hdfile_close(decoder);
    
    // 步骤4: 检查边界处的字符
    printf("\n步骤4: 检查边界处的字符...\n");
    
    // 读取原文件
    FILE* orig_file = fopen(test_filename, "rb");
    FILE* decoded_file = fopen(decoded_filename, "rb");
    
    if (orig_file == NULL || decoded_file == NULL) {
        printf("ERROR: 无法打开文件进行比较\n");
        return;
    }
    
    // 检查边界附近的字节
    size_t check_start = padding_size - 5;
    size_t check_end = padding_size + 10;
    
    fseek(orig_file, check_start, SEEK_SET);
    fseek(decoded_file, check_start, SEEK_SET);
    
    printf("检查位置 %zu-%zu 的字节:\n", check_start, check_end);
    printf("位置   原文件  解码文件  ASCII\n");
    printf("-----  ------  --------  -----\n");
    
    for (size_t pos = check_start; pos <= check_end; pos++) {
        int orig_byte = fgetc(orig_file);
        int decoded_byte = fgetc(decoded_file);
        
        printf("%5zu    %02X      %02X     ", pos, 
               orig_byte == EOF ? 0 : (unsigned char)orig_byte,
               decoded_byte == EOF ? 0 : (unsigned char)decoded_byte);
        
        if (orig_byte == decoded_byte && orig_byte != EOF) {
            printf("✓");
        } else {
            printf("✗");
        }
        
        if (pos == padding_size) {
            printf(" <-- 'é'第1字节");
        } else if (pos == padding_size + 1) {
            printf(" <-- 'é'第2字节");
        }
        printf("\n");
    }
    
    fclose(orig_file);
    fclose(decoded_file);
    
    // 清理资源
    free_huffman(hm);
    free_hdfile(encoder);
    free_hdfile(decoder);
    
    printf("\n=== 边界测试完成 ===\n");
}

int main() {
    test_buffer_boundary();
    return 0;
}
