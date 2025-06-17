#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include "sqlist.h"
#include "tools.h"
#include "huffman.h"
#include <stdio.h>

typedef FILE *file;
// typedef uint32_t utf8;

#define BUFFER_0_SIZE KB(64)

struct HandleFile{
    // 文件指针
    file _indata;
    file _outdata;
    // 文件路径
    // string _inpath;
    // string _outpath;
    // 缓冲区
    byte buffer;
    size_t size;
    size_t bit_pos;
    size_t buffer_pos;
}; // HandleFile
typedef struct HandleFile HandleFile,Hdfile;
typedef Hdfile *handlefile,*hdfile;

enum TheFile{
    INFILE,
    OUTFILE
};
typedef enum TheFile TheFile;

// 文件处理函数声明
hdfile new_hdfile();
Exception hdfile_open(hdfile self, const char *input_path, const char *output_path);
void hdfile_close(hdfile self);
void free_hdfile(hdfile self);

// UTF8字符频率统计
sqlist hdfile_count_frequency(hdfile self);

// 字长表读写
Exception hdfile_write_length_table(hdfile self, sqlist length_table);
sqlist hdfile_read_length_table(hdfile self);

// 编码解码
Exception hdfile_encode(hdfile self, sqlist code_table);
Exception hdfile_decode(hdfile self, hufftree tree);

#endif // HANDLEFILE_H