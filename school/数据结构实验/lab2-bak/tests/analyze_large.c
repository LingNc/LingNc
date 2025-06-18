#include <stdio.h>
#include <math.h>
#include "hdfile.h"

int main() {
    printf("=== 分析大文件total.txt的编码效率 ===\n");

    hdfile hf = new_hdfile();
    if (hf == NULL) {
        printf("创建hdfile失败\n");
        return 1;
    }

    Exception ex = hdfile_open(hf, "testdata/total.txt", NULL);
    if (ex.status != SUCCESS) {
        printf("打开文件失败: %s\n", ex.msg);
        free_hdfile(hf);
        return 1;
    }

    printf("开始统计频率...\n");
    sqlist freq_table = hdfile_count_frequency(hf);

    if (freq_table == NULL) {
        printf("频率统计失败\n");
        free_hdfile(hf);
        return 1;
    }

    size_t total_chars = sqlist_size(freq_table);
    printf("频率统计成功，字符种类: %zu\n", total_chars);

    // 计算总字符数和熵
    size_t total_count = 0;
    double entropy = 0.0;

    for (size_t i = 0; i < total_chars; i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        size_t freq = *(size_t*)p->second;
        total_count += freq;
    }

    printf("总字符数: %zu\n", total_count);

    // 显示频率最高的20个字符
    printf("\n频率最高的20个字符:\n");
    printf("字符\tUnicode\t频率\t百分比\n");
    printf("----\t-------\t----\t------\n");

    for (size_t i = 0; i < total_chars && i < 20; i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t freq = *(size_t*)p->second;
        double percentage = (double)freq / total_count * 100;

        if (ch == 32) {
            printf("空格\tU+%04lX\t%zu\t%.2f%%\n", ch, freq, percentage);
        } else if (ch == 10) {
            printf("\\n\tU+%04lX\t%zu\t%.2f%%\n", ch, freq, percentage);
        } else if (ch >= 32 && ch <= 126) {
            printf("%c\tU+%04lX\t%zu\t%.2f%%\n", (char)ch, ch, freq, percentage);
        } else {
            printf("?\tU+%04lX\t%zu\t%.2f%%\n", ch, freq, percentage);
        }

        // 计算熵的贡献
        if (freq > 0) {
            double p_i = (double)freq / total_count;
            entropy -= p_i * log2(p_i);
        }
    }

    printf("\n信息熵分析:\n");
    printf("信息熵: %.3f 位/字符\n", entropy);
    printf("理论最优编码长度: %.3f 位/字符\n", entropy);
    printf("ASCII固定编码: 8.000 位/字符\n");
    printf("理论压缩率: %.2f%%\n", (8.0 - entropy) / 8.0 * 100);

    free_hdfile(hf);
    return 0;
}
