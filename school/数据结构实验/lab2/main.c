#include "handlefile.h"
#include "huffman.h"
#include "exception.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_usage() {
    printf("哈夫曼编码/解码工具\n");
    printf("用法:\n");
    printf("  编码: ./main -c <输入文件> <输出文件>\n");
    printf("  解码: ./main -d <输入文件> <输出文件>\n");
}

int main(int argc, char* argv[]) {
    // 检查命令行参数
    if (argc != 4) {
        print_usage();
        return 1;
    }

    // 解析命令行参数
    char* mode = argv[1];
    char* input_file = argv[2];
    char* output_file = argv[3];

    // 判断操作模式: 编码 或 解码
    bool is_encode = false;

    if (strcmp(mode, "-c") == 0) {
        is_encode = true;
    } else if (strcmp(mode, "-d") == 0) {
        is_encode = false;
    } else {
        print_usage();
        return 1;
    }

    // 创建文件处理对象
    hdfile file_handler = new_hdfile();
    if (file_handler == NULL) {
        printf("错误: 无法创建文件处理对象\n");
        return 1;
    }

    // 加载输入文件
    Exception e = hdfile_load(file_handler, INFILE, input_file);
    if (e.status != SUCCESS) {
        printf("错误: %s\n", e.msg);
        free_hdfile(file_handler);
        return 1;
    }

    // 加载输出文件
    e = hdfile_load(file_handler, OUTFILE, output_file);
    if (e.status != SUCCESS) {
        printf("错误: %s\n", e.msg);
        free_hdfile(file_handler);
        return 1;
    }

    // 创建哈夫曼编码器
    huffman huff_coder = new_huffman();
    if (huff_coder == NULL) {
        printf("错误: 无法创建哈夫曼编码器\n");
        free_hdfile(file_handler);
        return 1;
    }

    if (is_encode) {
        // 编码模式
        printf("正在编码文件: %s -> %s\n", input_file, output_file);

        // 统计字符频率
        printf("分析字符频率...\n");
        sqlist freq_table = hdfile_freque(file_handler);
        if (freq_table == NULL) {
            printf("错误: 无法生成频率表\n");
            free_huffman(huff_coder);
            free_hdfile(file_handler);
            return 1;
        }

        // 加载频率表到哈夫曼编码器
        e = huffman_load(huff_coder, Freque, freq_table);
        if (e.status != SUCCESS) {
            printf("错误: %s\n", e.msg);
            free_huffman(huff_coder);
            free_hdfile(file_handler);
            return 1;
        }

        // 构建哈夫曼树
        printf("构建哈夫曼树...\n");
        e = huffman_build_tree_simple2(huff_coder); // 使用更简化版构建函数，避免使用pair
        if (e.status != SUCCESS) {
            printf("错误: %s\n", e.msg);
            free_huffman(huff_coder);
            free_hdfile(file_handler);
            return 1;
        }

        // 生成编码表
        printf("生成编码表...\n");
        sqlist code_table = huffman_encode(huff_coder);
        if (code_table == NULL) {
            printf("错误: 无法生成编码表\n");
            free_huffman(huff_coder);
            free_hdfile(file_handler);
            return 1;
        }

        // 写入编码后的数据
        printf("写入编码数据...\n");
        e = hdfile_write_encoded(file_handler, code_table, huff_coder->_lenthTalbe);
        if (e.status != SUCCESS) {
            printf("错误: %s\n", e.msg);
            free_huffman(huff_coder);
            free_hdfile(file_handler);
            return 1;
        }

        printf("编码完成!\n");

    } else {
        // 解码模式
        printf("正在解码文件: %s -> %s\n", input_file, output_file);

        // 读取长度表
        printf("读取编码信息...\n");
        sqlist length_table = hdfile_read_length_table(file_handler);
        if (length_table == NULL) {
            printf("错误: 无法读取长度表\n");
            free_huffman(huff_coder);
            free_hdfile(file_handler);
            return 1;
        }

        // 加载长度表到哈夫曼编码器
        e = huffman_load(huff_coder, Length, length_table);
        if (e.status != SUCCESS) {
            printf("错误: %s\n", e.msg);
            free_huffman(huff_coder);
            free_hdfile(file_handler);
            return 1;
        }

        // 重建哈夫曼树
        printf("重建哈夫曼树...\n");
        e = huffman_rebuild_tree_from_lengths(huff_coder);
        if (e.status != SUCCESS) {
            printf("错误: %s\n", e.msg);
            free_huffman(huff_coder);
            free_hdfile(file_handler);
            return 1;
        }

        // 解码数据
        printf("解码数据...\n");
        e = hdfile_decode(file_handler, huff_coder->_tree);
        if (e.status != SUCCESS) {
            printf("错误: %s\n", e.msg);
            free_huffman(huff_coder);
            free_hdfile(file_handler);
            return 1;
        }

        printf("解码完成!\n");
    }

    // 清理资源
    free_huffman(huff_coder);
    free_hdfile(file_handler);

    return 0;
}