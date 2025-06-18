#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../include/huffman.h"
#include "../include/hdfile.h"
#include "../include/tools.h"

void test_detailed_encode_decode() {
    printf("=== 详细测试编码解码过程 ===\n");
    
    const char* test_filename = "testdata/simple_utf8_test.txt";
    const char* encoded_filename = "testdata/simple_utf8_test.huf";
    const char* decoded_filename = "testdata/simple_utf8_test_decoded.txt";
    
    // 创建一个简单的测试文件，包含'é'字符
    printf("步骤1: 创建测试文件...\n");
    FILE* test_file = fopen(test_filename, "w");
    if (test_file == NULL) {
        printf("ERROR: 无法创建测试文件\n");
        return;
    }
    
    // 写入 "aé" - 一个ASCII字符和一个UTF-8字符
    const char* test_content = "aé";
    fwrite(test_content, 1, strlen(test_content), test_file);
    fclose(test_file);
    printf("✓ 测试文件创建成功: \"%s\"\n", test_content);
    
    // 使用主程序直接进行编码
    printf("\n步骤2: 使用主程序编码...\n");
    char encode_cmd[256];
    snprintf(encode_cmd, sizeof(encode_cmd), 
             "cd /home/lingnc/LingNc/school/数据结构实验/lab2-bak && ./main %s %s", 
             test_filename, encoded_filename);
    
    int encode_result = system(encode_cmd);
    if (encode_result != 0) {
        printf("ERROR: 编码命令失败，返回码: %d\n", encode_result);
        return;
    }
    printf("✓ 编码完成\n");
    
    // 检查编码文件
    printf("\n步骤3: 检查编码文件...\n");
    FILE* encoded_file = fopen(encoded_filename, "rb");
    if (encoded_file == NULL) {
        printf("ERROR: 无法打开编码文件\n");
        return;
    }
    
    fseek(encoded_file, 0, SEEK_END);
    long encoded_size = ftell(encoded_file);
    fseek(encoded_file, 0, SEEK_SET);
    
    printf("编码文件大小: %ld 字节\n", encoded_size);
    
    unsigned char* encoded_data = malloc(encoded_size);
    fread(encoded_data, 1, encoded_size, encoded_file);
    fclose(encoded_file);
    
    printf("编码文件内容 (十六进制):\n");
    for (long i = 0; i < encoded_size; i++) {
        printf("%02X ", encoded_data[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    if (encoded_size % 16 != 0) printf("\n");
    
    free(encoded_data);
    
    // 使用主程序进行解码
    printf("\n步骤4: 使用主程序解码...\n");
    char decode_cmd[256];
    snprintf(decode_cmd, sizeof(decode_cmd), 
             "cd /home/lingnc/LingNc/school/数据结构实验/lab2-bak && ./main %s %s", 
             encoded_filename, decoded_filename);
    
    int decode_result = system(decode_cmd);
    if (decode_result != 0) {
        printf("ERROR: 解码命令失败，返回码: %d\n", decode_result);
        return;
    }
    printf("✓ 解码完成\n");
    
    // 检查解码文件
    printf("\n步骤5: 检查解码文件...\n");
    FILE* decoded_file = fopen(decoded_filename, "rb");
    if (decoded_file == NULL) {
        printf("ERROR: 无法打开解码文件\n");
        return;
    }
    
    fseek(decoded_file, 0, SEEK_END);
    long decoded_size = ftell(decoded_file);
    fseek(decoded_file, 0, SEEK_SET);
    
    printf("解码文件大小: %ld 字节\n", decoded_size);
    
    if (decoded_size > 0) {
        unsigned char* decoded_data = malloc(decoded_size);
        fread(decoded_data, 1, decoded_size, decoded_file);
        fclose(decoded_file);
        
        printf("解码文件内容 (十六进制):\n");
        for (long i = 0; i < decoded_size; i++) {
            printf("%02X ", decoded_data[i]);
        }
        printf("\n");
        
        printf("解码文件内容 (字符串): \"");
        for (long i = 0; i < decoded_size; i++) {
            if (decoded_data[i] >= 32 && decoded_data[i] <= 126) {
                printf("%c", decoded_data[i]);
            } else {
                printf("\\x%02X", decoded_data[i]);
            }
        }
        printf("\"\n");
        
        // 比较原文件和解码文件
        printf("\n步骤6: 比较文件...\n");
        FILE* orig_file = fopen(test_filename, "rb");
        fseek(orig_file, 0, SEEK_END);
        long orig_size = ftell(orig_file);
        fseek(orig_file, 0, SEEK_SET);
        
        unsigned char* orig_data = malloc(orig_size);
        fread(orig_data, 1, orig_size, orig_file);
        fclose(orig_file);
        
        printf("原文件大小: %ld, 解码文件大小: %ld\n", orig_size, decoded_size);
        
        printf("原文件内容 (十六进制): ");
        for (long i = 0; i < orig_size; i++) {
            printf("%02X ", orig_data[i]);
        }
        printf("\n");
        
        printf("解码文件内容 (十六进制): ");
        for (long i = 0; i < decoded_size; i++) {
            printf("%02X ", decoded_data[i]);
        }
        printf("\n");
        
        // 检查是否有'é'字符的问题
        bool found_e_acute_orig = false;
        bool found_e_acute_decoded = false;
        bool found_replacement_char = false;
        
        for (long i = 0; i < orig_size - 1; i++) {
            if (orig_data[i] == 0xC3 && orig_data[i+1] == 0xA9) {
                printf("原文件: 在位置 %ld 找到'é' (0xC3 0xA9)\n", i);
                found_e_acute_orig = true;
                break;
            }
        }
        
        for (long i = 0; i < decoded_size - 1; i++) {
            if (decoded_data[i] == 0xC3 && decoded_data[i+1] == 0xA9) {
                printf("解码文件: 在位置 %ld 找到'é' (0xC3 0xA9)\n", i);
                found_e_acute_decoded = true;
            } else if (decoded_data[i] == 0xEF && i+2 < decoded_size && 
                      decoded_data[i+1] == 0xBF && decoded_data[i+2] == 0xBD) {
                printf("解码文件: 在位置 %ld 找到替换字符 (0xEF 0xBF 0xBD)\n", i);
                found_replacement_char = true;
            }
        }
        
        if (found_e_acute_orig && found_e_acute_decoded) {
            printf("✓ 'é'字符正确保存\n");
        } else if (found_e_acute_orig && found_replacement_char) {
            printf("✗ 'é'字符被替换为替换字符 - 这是问题所在!\n");
        } else if (found_e_acute_orig && !found_e_acute_decoded && !found_replacement_char) {
            printf("✗ 'é'字符完全丢失\n");
        }
        
        free(orig_data);
        free(decoded_data);
    } else {
        printf("解码文件为空!\n");
        fclose(decoded_file);
    }
    
    printf("\n=== 测试完成 ===\n");
}

int main() {
    test_detailed_encode_decode();
    return 0;
}
