#include <stdio.h>
#include <math.h>
#include "hdfile.h"

int main() {
    printf("=== 检查频率表结构和排序 ===\n");

    hdfile hf = new_hdfile();
    Exception ex = hdfile_open(hf, "testdata/test.txt", NULL);
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

    printf("原始频率表（应该按字符ASCII码排序）:\n");
    printf("索引\t字符\tASCII\t频率\n");
    printf("----\t----\t-----\t----\n");

    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t freq = *(size_t*)p->second;

        if (ch == 10) {
            printf("%zu\t\\n\t%lu\t%zu\n", i, ch, freq);
        } else if (ch == 32) {
            printf("%zu\t空格\t%lu\t%zu\n", i, ch, freq);
        } else if (ch >= 32 && ch <= 126) {
            printf("%zu\t%c\t%lu\t%zu\n", i, (char)ch, ch, freq);
        } else {
            printf("%zu\tU+%04lX\t%lu\t%zu\n", i, ch, ch, freq);
        }
    }

    // 检查是否按频率从高到低排序
    printf("\n检查排序：\n");
    bool freq_sorted_desc = true;
    bool ascii_sorted_asc = true;

    for (size_t i = 1; i < sqlist_size(freq_table); i++) {
        pair p1 = *(pair*)sqlist_at(freq_table, i-1);
        pair p2 = *(pair*)sqlist_at(freq_table, i);

        size_t freq1 = *(size_t*)p1->second;
        size_t freq2 = *(size_t*)p2->second;
        utf8 ch1 = *(utf8*)p1->first;
        utf8 ch2 = *(utf8*)p2->first;

        if (freq1 < freq2) freq_sorted_desc = false;
        if (ch1 > ch2) ascii_sorted_asc = false;
    }

    printf("按频率降序排列: %s\n", freq_sorted_desc ? "是" : "否");
    printf("按ASCII升序排列: %s\n", ascii_sorted_asc ? "是" : "否");

    // 构建哈夫曼编码，检查长度
    huffman huffman_encoder = new_huffman();
    Exception load_ex = huffman_load(huffman_encoder, freq_table);
    if (load_ex.status == SUCCESS) {
        Exception build_ex = huffman_build(huffman_encoder);
        if (build_ex.status == SUCCESS) {
            sqlist length_table = huffman_table(huffman_encoder, LENGTH_TABLE);
            if (length_table != NULL) {
                printf("\n哈夫曼编码长度分析:\n");
                size_t max_length = 0;
                size_t min_length = 999;

                for (size_t i = 0; i < sqlist_size(length_table); i++) {
                    pair p = *(pair*)sqlist_at(length_table, i);
                    size_t len = *(size_t*)p->second;
                    if (len > max_length) max_length = len;
                    if (len < min_length) min_length = len;
                }

                printf("最短编码长度: %zu 位\n", min_length);
                printf("最长编码长度: %zu 位\n", max_length);
                printf("字符数量: %zu\n", sqlist_size(length_table));
                printf("理论最短长度: %.2f 位\n", log2(sqlist_size(length_table)));
            }
        }
    }

    free_huffman(huffman_encoder);
    free_hdfile(hf);
    return 0;
}
