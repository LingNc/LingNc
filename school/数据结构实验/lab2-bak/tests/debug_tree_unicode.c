#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../include/huffman.h"
#include "../include/hdfile.h"
#include "../include/tools.h"

// Test function to debug Unicode preservation in Huffman tree
void test_huffman_tree_unicode() {
    printf("=== 测试霍夫曼树中的Unicode值保存 ===\n");

    // 创建简单的频率表，包含'é'字符
    utf8 char_e_acute = 0x00E9;  // 'é' - U+00E9
    utf8 char_a = 0x0061;        // 'a' - U+0061
    utf8 char_b = 0x0062;        // 'b' - U+0062

    size_t freq_e = 10;
    size_t freq_a = 5;
    size_t freq_b = 3;

    // 创建频率表
    interfaces pair_inters = pair_create_inters();
    sqlist freq_table = new_sqlist(pair_inters);

    // 添加字符频率对
    pair p1 = new_pair(&char_e_acute, &freq_e, pair_inters);
    pair p2 = new_pair(&char_a, &freq_a, pair_inters);
    pair p3 = new_pair(&char_b, &freq_b, pair_inters);

    sqlist_push_back(freq_table, &p1);
    sqlist_push_back(freq_table, &p2);
    sqlist_push_back(freq_table, &p3);

    printf("创建的频率表：\n");
    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t freq = *(size_t*)p->second;
        printf("  字符: U+%04X (十进制: %lu), 频率: %zu\n", (unsigned int)ch, ch, freq);
    }

    // 创建Huffman编码器
    huffman hm = new_huffman();
    huffman_load(hm, Freque, freq_table);

    // 构建Huffman树
    hufftree tree = huffman_build(hm);
    if (tree == NULL) {
        printf("ERROR: 无法构建Huffman树\n");
        return;
    }

    printf("\n=== 构建的霍夫曼树验证 ===\n");

    // 获取字长表和编码表
    sqlist length_table = huffman_table(hm, Length);
    sqlist code_table = huffman_table(hm, Code);

    printf("字长表：\n");
    for (size_t i = 0; i < sqlist_size(length_table); i++) {
        pair p = *(pair*)sqlist_at(length_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t length = *(size_t*)p->second;
        printf("  字符: U+%04X (十进制: %lu), 字长: %zu\n", (unsigned int)ch, ch, length);
    }

    printf("\n编码表：\n");
    for (size_t i = 0; i < sqlist_size(code_table); i++) {
        pair p = *(pair*)sqlist_at(code_table, i);
        utf8 ch = *(utf8*)p->first;
        huffcode code = (huffcode)p->second;
        printf("  字符: U+%04X (十进制: %lu), 编码: ", (unsigned int)ch, ch);

        // 显示编码的位
        for (int j = code->_size - 1; j >= 0; j--) {
            bool bit = (code->_code >> j) & 1;
            printf("%d", bit ? 1 : 0);
        }
        printf(" (长度: %u)\n", code->_size);
    }

    // 现在测试重新构建的树
    printf("\n=== 测试从编码表重建的树 ===\n");
    hufftree rebuilt_tree = hufftree_from_code_table(code_table);

    if (rebuilt_tree == NULL) {
        printf("ERROR: 无法从编码表重建树\n");
        return;
    }

    // 验证重建的树中的Unicode值
    printf("验证重建树中的叶子节点：\n");

    // 手动遍历每个编码，验证对应的字符
    for (size_t i = 0; i < sqlist_size(code_table); i++) {
        pair p = *(pair*)sqlist_at(code_table, i);
        utf8 expected_char = *(utf8*)p->first;
        huffcode code = (huffcode)p->second;

        printf("  验证字符 U+%04X (十进制: %lu):\n", (unsigned int)expected_char, expected_char);

        // 从根节点开始，按照编码路径到达叶子节点
        huffnode current = rebuilt_tree;

        for (int bit_idx = code->_size - 1; bit_idx >= 0; bit_idx--) {
            bool bit = (code->_code >> bit_idx) & 1;
            printf("    位 %d: %d -> ", code->_size - 1 - bit_idx, bit ? 1 : 0);

            if (bit == 0) {
                current = current->left;
                printf("左子树");
            } else {
                current = current->right;
                printf("右子树");
            }

            if (current == NULL) {
                printf(" -> NULL (错误!)\n");
                break;
            } else {
                printf(" -> 节点 (word: U+%04X)\n", (unsigned int)current->word);
            }
        }

        if (current != NULL && current->left == NULL && current->right == NULL) {
            printf("    到达叶子节点: U+%04X (十进制: %lu)\n", (unsigned int)current->word, current->word);
            if (current->word == expected_char) {
                printf("    ✓ Unicode值正确保存\n");
            } else {
                printf("    ✗ Unicode值错误! 期望: U+%04X, 实际: U+%04X\n",
                       (unsigned int)expected_char, (unsigned int)current->word);
            }
        } else {
            printf("    ✗ 未能到达叶子节点或路径错误\n");
        }
        printf("\n");
    }

    // 清理资源
    free_huffman(hm);
    free_sqlist(freq_table);
    free_pair(p1);
    free_pair(p2);
    free_pair(p3);
}

int main() {
    test_huffman_tree_unicode();
    return 0;
}
