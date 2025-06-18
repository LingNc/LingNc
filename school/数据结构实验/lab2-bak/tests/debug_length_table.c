#include "huffman.h"
#include "hdfile.h"
#include "tools.h"
#include "pair.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== 调试字长表排序和编码生成 ===\n");

    // 1. 创建文件处理器
    hdfile hf = new_hdfile();
    if (hf == NULL) {
        printf("错误：无法创建文件处理器\n");
        return 1;
    }

    // 2. 统计字符频率
    Exception ex = hdfile_open(hf, "testdata/total.txt", NULL);
    if (ex.status != SUCCESS) {
        printf("错误：无法打开文件\n");
        return 1;
    }

    sqlist freq_table = hdfile_count_frequency(hf);
    if (freq_table == NULL) {
        printf("错误：频率统计失败\n");
        return 1;
    }
    hdfile_close(hf);

    printf("字符种类: %zu\n", sqlist_size(freq_table));

    // 3. 构建Huffman树
    huffman hm = new_huffman();
    huffman_load(hm, Freque, freq_table);
    hufftree tree = huffman_build(hm);

    // 4. 获取字长表
    sqlist length_table = huffman_table(hm, Length);

    printf("\n=== 字长表排序前 (前20个) ===\n");
    printf("字符\t频率\t长度\n");
    printf("----\t----\t----\n");

    size_t display_count = sqlist_size(length_table) > 20 ? 20 : sqlist_size(length_table);
    for (size_t i = 0; i < display_count; i++) {
        pair p = *(pair*)sqlist_at(length_table, i);
        utf8 ch = *(utf8*)p->first;
        size_t length = *(size_t*)p->second;

        // 查找频率
        size_t freq = 0;
        for (size_t j = 0; j < sqlist_size(freq_table); j++) {
            pair freq_p = *(pair*)sqlist_at(freq_table, j);
            if (*(utf8*)freq_p->first == ch) {
                freq = *(size_t*)freq_p->second;
                break;
            }
        }

        if (ch >= 32 && ch <= 126) {
            printf("'%c'\t%zu\t%zu\n", (char)ch, freq, length);
        } else if (ch == 10) {
            printf("\\n\t%zu\t%zu\n", freq, length);
        } else if (ch == 32) {
            printf("空格\t%zu\t%zu\n", freq, length);
        } else {
            printf("U+%04lX\t%zu\t%zu\n", ch, freq, length);
        }
    }

    // 5. 检查高频字符的编码长度
    printf("\n=== 高频字符编码长度检查 ===\n");
    printf("字符\t频率\t百分比\t编码长度\n");
    printf("----\t----\t----\t----\n");

    // 找出频率最高的10个字符
    typedef struct {
        utf8 ch;
        size_t freq;
        size_t length;
    } CharInfo;

    CharInfo top_chars[10];
    size_t top_count = 0;

    // 计算总字符数
    size_t total_chars = 0;
    for (size_t i = 0; i < sqlist_size(freq_table); i++) {
        pair p = *(pair*)sqlist_at(freq_table, i);
        total_chars += *(size_t*)p->second;
    }

    // 直接从频率表获取前10个（已按频率排序）
    for (size_t i = 0; i < sqlist_size(freq_table) && i < 10; i++) {
        pair freq_p = *(pair*)sqlist_at(freq_table, i);
        utf8 ch = *(utf8*)freq_p->first;
        size_t freq = *(size_t*)freq_p->second;

        // 查找编码长度
        size_t length = 0;
        for (size_t j = 0; j < sqlist_size(length_table); j++) {
            pair len_p = *(pair*)sqlist_at(length_table, j);
            if (*(utf8*)len_p->first == ch) {
                length = *(size_t*)len_p->second;
                break;
            }
        }

        top_chars[i].ch = ch;
        top_chars[i].freq = freq;
        top_chars[i].length = length;
        top_count++;
    }

    // 显示top字符
    for (size_t i = 0; i < top_count; i++) {
        CharInfo info = top_chars[i];
        double percentage = (double)info.freq / total_chars * 100.0;

        if (info.ch >= 32 && info.ch <= 126) {
            printf("'%c'\t%zu\t%.1f%%\t%zu\n", (char)info.ch, info.freq, percentage, info.length);
        } else if (info.ch == 10) {
            printf("\\n\t%zu\t%.1f%%\t%zu\n", info.freq, percentage, info.length);
        } else if (info.ch == 32) {
            printf("空格\t%zu\t%.1f%%\t%zu\n", info.freq, percentage, info.length);
        } else {
            printf("U+%04lX\t%zu\t%.1f%%\t%zu\n", info.ch, info.freq, percentage, info.length);
        }
    }

    // 6. 清理资源
    // free_huffman(hm);  // 暂时注释以避免崩溃
    // free_sqlist(freq_table);
    // free_hdfile(hf);

    return 0;
}
