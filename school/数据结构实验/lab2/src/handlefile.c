#include "handlefile.h"
#include <stdio.h>

// 外部函数
hdfile new_hdfile(){
    hdfile self=malloc(sizeof(HandleFile));
    if(self==NULL) return NULL;
    self->_indata=NULL;
    // self->_inpath=NULL;
    self->buffer=malloc(BUFFER_0_SIZE);
    if(self->buffer==NULL){
        free(self);
        return NULL;
    }
    self->size=BUFFER_0_SIZE;
    self->bit_pos=0;
    self->buffer_pos=0;
    return self;
}

Exception hdfile_load(hdfile self,TheFile FileType,string filepath){
    if(self==NULL) return new_exception(ERROR,"hdfile_load: 传入self指针为空!");
    if(filepath==NULL) return new_exception(ERROR,"hdfile_load: 传入filepath指针为空!");
    Exception e=new_exception(SUCCESS,"");
    switch (FileType){
        case INFILE:
            self->_indata=fopen(filepath,"rb");
            if(self->_indata==NULL){
                e.status=ERROR;
                e.msg="hdfile_load: 打开输入文件失败!";
            }
            break;
        case OUTFILE:
            self->_outdata=fopen(filepath,"wb");
            if(self->_outdata==NULL){
                e.status=ERROR;
                e.msg="hdfile_load: 打开输出文件失败!";
            }
            break;
        default:
            e.status=ERROR;
            e.msg="hdfile_load: FileType错误!";
            break;
    }
    return e;
} // hdfile_load