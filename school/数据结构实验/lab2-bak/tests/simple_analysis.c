#include <stdio.h>
#include <math.h>
#include "hdfile.h"

int main() {
    printf("=== 简化的编码效率分析 ===\n");

    hdfile hf = new_hdfile();
    Exception ex = hdfile_open(hf, "testdata/test.txt", NULL);
    if (ex.status != SUCCESS) {
        printf("打开文件失败\n");
        free_hdfile(hf);
        return 1;
    }

    // 统计频率
    sqlist freq_table = hdfile_count_frequency(hf);
    if (freq_table == NULL) {
        printf("频率统计失败\n");
        free_hdfile(hf);
        return 1;
    }

    printf("字符种类: %zu\n", sqlist_size(freq_table));

    // 显示频率分布
    size_t total_count = 0;
    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        size_t freq = *(size_t*)p->second;
        total_count += freq;
    }

    printf("总字符数: %zu\n", total_count);
    printf("\n字符频率分布:\n");

    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t freq = *(size_t*)p->second;
        double percentage = (double)freq / total_count * 100;

        if (ch == 32) {
            printf("空格: %zu次 (%.1f%%)\n", freq, percentage);
        } else if (ch == 10) {
            printf("\\n: %zu次 (%.1f%%)\n", freq, percentage);
        } else if (ch >= 32 && ch <= 126) {
            printf("'%c': %zu次 (%.1f%%)\n", (char)ch, freq, percentage);
        } else {
            printf("U+%04lX: %zu次 (%.1f%%)\n", ch, freq, percentage);
        }
    }

    // 创建哈夫曼编码器
    huffman huffman_encoder = new_huffman();
    Exception load_ex = huffman_load(huffman_encoder, Freque, freq_table);
    if (load_ex.status != SUCCESS) {
        printf("加载频率表失败: %s\n", load_ex.msg);
        free_huffman(huffman_encoder);
        free_hdfile(hf);
        return 1;
    }

    hufftree tree = huffman_build(huffman_encoder);
    if (tree == NULL) {
        printf("构建哈夫曼树失败\n");
        free_huffman(huffman_encoder);
        free_hdfile(hf);
        return 1;
    }

    sqlist length_table = huffman_table(huffman_encoder, Length);
    sqlist code_table = huffman_table(huffman_encoder, Code);

    if (length_table == NULL || code_table == NULL) {
        printf("获取编码表失败\n");
        free_huffman(huffman_encoder);
        free_hdfile(hf);
        return 1;
    }

    printf("\n哈夫曼编码表:\n");
    size_t total_bits = 0;

    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair freq_p = *(pair*)sqlist_at(freq_table, i);
        pair len_p = *(pair*)sqlist_at(length_table, i);
        pair code_p = *(pair*)sqlist_at(code_table, i);

        utf8 ch = *(utf8*)freq_p->first;
        size_t freq = *(size_t*)freq_p->second;
        size_t len = *(size_t*)len_p->second;
        huffcode code = (huffcode)code_p->second;

        total_bits += freq * len;

        if (ch == 32) {
            printf("空格: 长度%zu, 频率%zu, 贡献%zu位\n", len, freq, freq * len);
        } else if (ch == 10) {
            printf("\\n: 长度%zu, 频率%zu, 贡献%zu位\n", len, freq, freq * len);
        } else if (ch >= 32 && ch <= 126) {
            printf("'%c': 长度%zu, 频率%zu, 贡献%zu位\n", (char)ch, len, freq, freq * len);
        } else {
            printf("U+%04lX: 长度%zu, 频率%zu, 贡献%zu位\n", ch, len, freq, freq * len);
        }
    }

    printf("\n编码效率总结:\n");
    printf("原始大小: %zu字符 × 8位 = %zu位\n", total_count, total_count * 8);
    printf("编码大小: %zu位\n", total_bits);
    printf("理论压缩率: %.2f%%\n", (1.0 - (double)total_bits / (total_count * 8)) * 100);
    printf("平均编码长度: %.3f位/字符\n", (double)total_bits / total_count);

    free_huffman(huffman_encoder);
    free_hdfile(hf);
    return 0;
}
