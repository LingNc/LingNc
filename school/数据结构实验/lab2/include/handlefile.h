#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include "sqlist.h"
#include "tools.h"
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

hdfile new_hdfile();
Exception hdfile_load(hdfile self,TheFile FileType,string filepath);
utf8 hdfile_read_utf8(hdfile self);
// hdfile new_hdfile_from(file fp);
// hdfile hdfile_init(hdfile self,string filepath);
sqlist hdfile_freque(hdfile self);
Exception free_hdfile(hdfile self);

#endif // HANDLEFILE_H