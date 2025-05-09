#include "huffman.h"
#include "interface.h"
#include <stdlib.h>

huffman new_huffman(){
    huffman res=malloc(sizeof(struct Huffman));
    if(res==NULL) return NULL;
    res->_tree=NULL;
    res->_nodes=0;
    res->_frequeTable=NULL;
    res->_lenthTalbe=NULL;
    res->_codeTable=NULL;
    return res;
}

Exception huffman_load(huffman self,Table type,sqlist table){
    if(self==NULL) return new_exception(ERROR,"huffman_load: 传入self指针为空!");
    if(table==NULL) return new_exception(ERROR,"huffman_load: 传入table指针为空!");
    Exception e=new_exception(SUCCESS,"");
    switch (type){
        case Freque:
            self->_frequeTable=table;
            break;
        case Length:
            self->_lenthTalbe=table;
            break;
        case Code:
            self->_codeTable=table;
            break;
        default:
            e.status=ERROR;
            e.msg="huffman_load: type错误!";
            break;
    }
    return e;
}
// 根据频率表构造哈夫曼树
node create(huffman self){

}

sqlist huffman_encode(huffman self){

}
sqlist huffman_decode(huffman self){

}
Exception free_huffman(huffman self){

}