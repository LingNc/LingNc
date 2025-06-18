#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../include/huffman.h"
#include "../include/hdfile.h"
#include "../include/tools.h"

// Simple test function to debug step by step
void test_simple_unicode() {
    printf("=== 简单Unicode测试 ===\n");
    
    // Test 1: Basic interface creation
    printf("步骤1: 创建接口...\n");
    
    // 创建utf8接口
    interface utf8_inter = new_interface(sizeof(utf8), NULL, "");
    if (utf8_inter == NULL) {
        printf("ERROR: 无法创建utf8接口\n");
        return;
    }
    printf("✓ utf8接口创建成功\n");
    
    // 创建size_t接口
    interface size_t_inter = new_interface(sizeof(size_t), NULL, "");
    if (size_t_inter == NULL) {
        printf("ERROR: 无法创建size_t接口\n");
        return;
    }
    printf("✓ size_t接口创建成功\n");
    
    // 创建pair接口
    interfaces pair_inters = new_interfaces(NULL, 2, utf8_inter, size_t_inter);
    if (pair_inters == NULL) {
        printf("ERROR: 无法创建pair接口\n");
        return;
    }
    printf("✓ pair接口创建成功\n");
    
    // Test 2: Create pairs
    printf("\n步骤2: 创建字符频率对...\n");
    
    utf8 char_e_acute = 0x00E9;  // 'é' - U+00E9
    size_t freq_e = 10;
    
    printf("准备创建字符: U+%04X (十进制: %lu), 频率: %zu\n", 
           (unsigned int)char_e_acute, char_e_acute, freq_e);
    
    pair p1 = new_pair(&char_e_acute, &freq_e, pair_inters);
    if (p1 == NULL) {
        printf("ERROR: 无法创建pair\n");
        return;
    }
    printf("✓ pair创建成功\n");
    
    // Verify pair contents
    utf8 retrieved_char = *(utf8*)p1->first;
    size_t retrieved_freq = *(size_t*)p1->second;
    printf("验证pair内容: 字符 U+%04X (十进制: %lu), 频率: %zu\n", 
           (unsigned int)retrieved_char, retrieved_char, retrieved_freq);
    
    // Test 3: Create sqlist and add pair
    printf("\n步骤3: 创建sqlist并添加pair...\n");
    
    interfaces pair_ptr_inters = pair_ptr_create_inters();
    if (pair_ptr_inters == NULL) {
        printf("ERROR: 无法创建pair指针接口\n");
        return;
    }
    printf("✓ pair指针接口创建成功\n");
    
    sqlist freq_table = new_sqlist(pair_ptr_inters);
    if (freq_table == NULL) {
        printf("ERROR: 无法创建sqlist\n");
        return;
    }
    printf("✓ sqlist创建成功\n");
    
    Exception ex = sqlist_push_back(freq_table, &p1);
    if (ex.status != SUCCESS) {
        printf("ERROR: 无法添加pair到sqlist: %s\n", ex.msg);
        return;
    }
    printf("✓ pair添加到sqlist成功\n");
    
    // Verify sqlist contents
    if (sqlist_size(freq_table) > 0) {
        pair retrieved_p = *(pair*)sqlist_at(freq_table, 0);
        utf8 final_char = *(utf8*)retrieved_p->first;
        size_t final_freq = *(size_t*)retrieved_p->second;
        printf("验证sqlist内容: 字符 U+%04X (十进制: %lu), 频率: %zu\n", 
               (unsigned int)final_char, final_char, final_freq);
    }
    
    // Test 4: Create huffman and load table
    printf("\n步骤4: 创建Huffman编码器...\n");
    
    huffman hm = new_huffman();
    if (hm == NULL) {
        printf("ERROR: 无法创建Huffman编码器\n");
        return;
    }
    printf("✓ Huffman编码器创建成功\n");
    
    ex = huffman_load(hm, Freque, freq_table);
    if (ex.status != SUCCESS) {
        printf("ERROR: 无法加载频率表: %s\n", ex.msg);
        return;
    }
    printf("✓ 频率表加载成功\n");
    
    // Test 5: Build tree
    printf("\n步骤5: 构建Huffman树...\n");
    
    hufftree tree = huffman_build(hm);
    if (tree == NULL) {
        printf("ERROR: 无法构建Huffman树\n");
        return;
    }
    printf("✓ Huffman树构建成功\n");
    
    // Test 6: Check tree content
    printf("\n步骤6: 检查树内容...\n");
    
    if (tree->left == NULL && tree->right == NULL) {
        // Single node tree
        printf("单节点树，字符: U+%04X (十进制: %lu)\n", 
               (unsigned int)tree->word, tree->word);
    } else {
        printf("多节点树，根节点频率: %zu\n", tree->freq);
        if (tree->left && tree->left->left == NULL && tree->left->right == NULL) {
            printf("  左叶子节点: U+%04X (十进制: %lu)\n", 
                   (unsigned int)tree->left->word, tree->left->word);
        }
        if (tree->right && tree->right->left == NULL && tree->right->right == NULL) {
            printf("  右叶子节点: U+%04X (十进制: %lu)\n", 
                   (unsigned int)tree->right->word, tree->right->word);
        }
    }
    
    printf("✓ 所有步骤完成\n");
    
    // 清理资源
    free_huffman(hm);
    free_sqlist(freq_table);
    free_pair(p1);
    
    printf("=== 测试完成 ===\n");
}

int main() {
    test_simple_unicode();
    return 0;
}
