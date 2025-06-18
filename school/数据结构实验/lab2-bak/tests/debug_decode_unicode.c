#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../include/huffman.h"
#include "../include/hdfile.h"
#include "../include/tools.h"

// Test function to debug actual decode process
void test_huffman_decode_unicode() {
    printf("=== 测试霍夫曼解码过程中的Unicode值 ===\n");
    
    // 创建包含多个字符的频率表，包括'é'字符
    utf8 char_e_acute = 0x00E9;  // 'é' - U+00E9
    utf8 char_a = 0x0061;        // 'a' - U+0061
    utf8 char_space = 0x0020;    // ' ' - U+0020
    
    size_t freq_e = 3;
    size_t freq_a = 5;
    size_t freq_space = 2;
    
    printf("创建频率表包含:\n");
    printf("  'é' (U+%04X): 频率 %zu\n", (unsigned int)char_e_acute, freq_e);
    printf("  'a' (U+%04X): 频率 %zu\n", (unsigned int)char_a, freq_a);
    printf("  ' ' (U+%04X): 频率 %zu\n", (unsigned int)char_space, freq_space);
    
    // 创建频率表
    interface utf8_inter = new_interface(sizeof(utf8), NULL, "");
    interface size_t_inter = new_interface(sizeof(size_t), NULL, "");
    interfaces pair_inters = new_interfaces(NULL, 2, utf8_inter, size_t_inter);
    interfaces pair_ptr_inters = pair_ptr_create_inters();
    sqlist freq_table = new_sqlist(pair_ptr_inters);
    
    // 添加字符频率对
    pair p1 = new_pair(&char_e_acute, &freq_e, pair_inters);
    pair p2 = new_pair(&char_a, &freq_a, pair_inters);
    pair p3 = new_pair(&char_space, &freq_space, pair_inters);
    
    sqlist_push_back(freq_table, &p1);
    sqlist_push_back(freq_table, &p2);
    sqlist_push_back(freq_table, &p3);
    
    // 创建Huffman编码器并构建树
    huffman hm = new_huffman();
    huffman_load(hm, Freque, freq_table);
    hufftree tree = huffman_build(hm);
    
    if (tree == NULL) {
        printf("ERROR: 无法构建Huffman树\n");
        return;
    }
    
    // 获取编码表
    sqlist code_table = huffman_table(hm, Code);
    if (code_table == NULL) {
        printf("ERROR: 无法获取编码表\n");
        return;
    }
    
    printf("\n=== 编码表内容 ===\n");
    for (size_t i = 0; i < sqlist_size(code_table); i++) {
        pair p = *(pair*)sqlist_at(code_table, i);
        utf8 ch = *(utf8*)p->first;
        huffcode code = (huffcode)p->second;
        
        printf("字符 U+%04X: 编码 ", (unsigned int)ch);
        for (int j = code->_size - 1; j >= 0; j--) {
            bool bit = (code->_code >> j) & 1;
            printf("%d", bit ? 1 : 0);
        }
        printf(" (长度: %u)\n", code->_size);
    }
    
    // 重新构建解码树
    printf("\n=== 测试解码树构建 ===\n");
    hufftree decode_tree = hufftree_from_code_table(code_table);
    if (decode_tree == NULL) {
        printf("ERROR: 无法构建解码树\n");
        return;
    }
    printf("✓ 解码树构建成功\n");
    
    // 测试每个字符的解码路径
    printf("\n=== 测试解码路径 ===\n");
    for (size_t i = 0; i < sqlist_size(code_table); i++) {
        pair p = *(pair*)sqlist_at(code_table, i);
        utf8 expected_char = *(utf8*)p->first;
        huffcode code = (huffcode)p->second;
        
        printf("测试字符 U+%04X 的解码:\n", (unsigned int)expected_char);
        printf("  编码: ");
        for (int j = code->_size - 1; j >= 0; j--) {
            bool bit = (code->_code >> j) & 1;
            printf("%d", bit ? 1 : 0);
        }
        printf("\n");
        
        // 模拟解码过程
        huffnode current = decode_tree;
        printf("  解码路径: 根");
        
        for (int bit_idx = code->_size - 1; bit_idx >= 0; bit_idx--) {
            bool bit = (code->_code >> bit_idx) & 1;
            
            if (bit == 0) {
                current = current->left;
                printf(" -> 左");
            } else {
                current = current->right;
                printf(" -> 右");
            }
            
            if (current == NULL) {
                printf(" -> NULL (错误!)\n");
                break;
            }
            
            if (current->left == NULL && current->right == NULL) {
                printf(" -> 叶子节点\n");
                break;
            }
        }
        
        if (current != NULL && current->left == NULL && current->right == NULL) {
            printf("  解码结果: U+%04X (十进制: %lu)\n", (unsigned int)current->word, current->word);
            if (current->word == expected_char) {
                printf("  ✓ 解码正确\n");
            } else {
                printf("  ✗ 解码错误! 期望: U+%04X, 实际: U+%04X\n", 
                       (unsigned int)expected_char, (unsigned int)current->word);
            }
        } else {
            printf("  ✗ 未能到达正确的叶子节点\n");
        }
        printf("\n");
    }
    
    printf("=== 测试完成，不进行资源清理以避免段错误 ===\n");
}

int main() {
    test_huffman_decode_unicode();
    return 0;
}
