#include <stdio.h>
#include "hdfile.h"

int main() {
    printf("=== 调试频率统计 ===\n");

    hdfile hf = new_hdfile();
    if (hf == NULL) {
        printf("创建hdfile失败\n");
        return 1;
    }

    Exception ex = hdfile_open(hf, "testdata/debug_test.txt", NULL);
    if (ex.status != SUCCESS) {
        printf("打开文件失败: %s\n", ex.msg);
        free_hdfile(hf);
        return 1;
    }

    printf("开始统计频率...\n");
    sqlist freq_table = hdfile_count_frequency(hf);

    if (freq_table == NULL) {
        printf("频率统计失败\n");
    } else {
        printf("频率统计成功，字符种类: %zu\n", sqlist_size(freq_table));

        // 显示前几个字符
        for (size_t i = 0; i < sqlist_size(freq_table) && i < 10; i++) {
            pair p = *(pair*)sqlist_at(freq_table, i);
            utf8 ch = *(utf8*)p->first;
            size_t freq = *(size_t*)p->second;
            printf("字符 %lu (ASCII %c): %zu次\n", ch, (char)ch, freq);
        }
    }

    free_hdfile(hf);
    return 0;
}
