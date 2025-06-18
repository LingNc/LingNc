#include <stdio.h>
#include <math.h>
#include "hdfile.h"

int main() {
    printf("=== 分析哈夫曼编码实际效率 ===\n");

    // 首先分析字符分布
    hdfile hf = new_hdfile();
    Exception ex = hdfile_open(hf, "testdata/total.txt", NULL);
    if (ex.status != SUCCESS) {
        printf("打开文件失败\n");
        free_hdfile(hf);
        return 1;
    }

    sqlist freq_table = hdfile_count_frequency(hf);
    if (freq_table == NULL) {
        printf("频率统计失败\n");
        free_hdfile(hf);
        return 1;
    }

    // 计算总字符数
    size_t total_count = 0;
    size_t total_chars = sqlist_size(freq_table);

    for (size_t i = 0; i < total_chars; i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        size_t freq = *(size_t*)p->second;
        total_count += freq;
    }

    printf("字符种类: %zu, 总字符数: %zu\n", total_chars, total_count);

    // 生成哈夫曼编码表
    huffman huffman_encoder = new_huffman();
    Exception load_ex = huffman_load(huffman_encoder, freq_table);
    if (load_ex.status != SUCCESS) {
        printf("加载频率表失败\n");
        free_huffman(huffman_encoder);
        free_hdfile(hf);
        return 1;
    }

    Exception build_ex = huffman_build(huffman_encoder);
    if (build_ex.status != SUCCESS) {
        printf("构建哈夫曼树失败\n");
        free_huffman(huffman_encoder);
        free_hdfile(hf);
        return 1;
    }

    sqlist length_table = huffman_table(huffman_encoder, LENGTH_TABLE);
    sqlist code_table = huffman_table(huffman_encoder, CODE_TABLE);

    if (length_table == NULL || code_table == NULL) {
        printf("获取编码表失败\n");
        free_huffman(huffman_encoder);
        free_hdfile(hf);
        return 1;
    }

    // 计算实际编码长度
    size_t total_bits = 0;
    double weighted_avg_length = 0.0;

    printf("\n前30个字符的编码分析:\n");
    printf("字符\t频率\t编码长度\t贡献位数\t百分比\n");
    printf("----\t----\t--------\t--------\t------\n");

    for (size_t i = 0; i < total_chars && i < 30; i++) {
        pair freq_p = *(pair*)sqlist_at(freq_table, i);
        pair len_p = *(pair*)sqlist_at(length_table, i);

        utf8 ch = *(utf8*)freq_p->first;
        size_t freq = *(size_t*)freq_p->second;
        size_t len = *(size_t*)len_p->second;

        size_t bits_contribution = freq * len;
        total_bits += bits_contribution;

        double percentage = (double)freq / total_count * 100;
        weighted_avg_length += ((double)freq / total_count) * len;

        if (ch == 32) {
            printf("空格\t%zu\t%zu\t\t%zu\t\t%.2f%%\n", freq, len, bits_contribution, percentage);
        } else if (ch == 10) {
            printf("\\n\t%zu\t%zu\t\t%zu\t\t%.2f%%\n", freq, len, bits_contribution, percentage);
        } else if (ch >= 32 && ch <= 126) {
            printf("%c\t%zu\t%zu\t\t%zu\t\t%.2f%%\n", (char)ch, freq, len, bits_contribution, percentage);
        } else {
            printf("U+%04lX\t%zu\t%zu\t\t%zu\t\t%.2f%%\n", ch, freq, len, bits_contribution, percentage);
        }
    }

    // 计算剩余字符的贡献
    for (size_t i = 30; i < total_chars; i++) {
        pair freq_p = *(pair*)sqlist_at(freq_table, i);
        pair len_p = *(pair*)sqlist_at(length_table, i);

        size_t freq = *(size_t*)freq_p->second;
        size_t len = *(size_t*)len_p->second;

        total_bits += freq * len;
        weighted_avg_length += ((double)freq / total_count) * len;
    }

    printf("\n编码效率分析:\n");
    printf("原始大小: %zu 字符 × 8位 = %zu 位\n", total_count, total_count * 8);
    printf("编码大小: %zu 位\n", total_bits);
    printf("平均编码长度: %.3f 位/字符\n", weighted_avg_length);
    printf("理论压缩率: %.2f%%\n", (1.0 - (double)total_bits / (total_count * 8)) * 100);

    // 检查编码表的最大长度
    size_t max_length = 0;
    for (size_t i = 0; i < total_chars; i++) {
        pair len_p = *(pair*)sqlist_at(length_table, i);
        size_t len = *(size_t*)len_p->second;
        if (len > max_length) max_length = len;
    }
    printf("最大编码长度: %zu 位\n", max_length);

    free_huffman(huffman_encoder);
    free_hdfile(hf);
    return 0;
}
