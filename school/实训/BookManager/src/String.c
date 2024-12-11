#include "String.h"
#include <stdlib.h>
#include <string.h>

// c_str 函数实现
char *_string_c_str(string this){
    return this->str;
}

// append_char 函数实现
string _string_append_char(string this,char c){
    this->str=(char *)realloc(this->str,this->length+2);
    this->str[this->length]=c;
    this->str[this->length+1]='\0';
    this->length+=1;
    return this;
}

// append_cstr 函数实现
string _string_append_cstr(string this,const char *s){
    size_t len=strlen(s);
    this->str=(char *)realloc(this->str,this->length+len+1);
    memcpy(this->str+this->length,s,len+1);
    this->length+=len;
    return this;
}

// append_string 函数实现
string _string_append_string(string this,string other){
    return _string_append_cstr(this,other->str);
}

// insert_char 函数实现
string _string_insert_char(string this,size_t pos,char c){
    if(pos>this->length) pos=this->length;
    this->str=(char *)realloc(this->str,this->length+2);
    memmove(this->str+pos+1,this->str+pos,this->length-pos+1);
    this->str[pos]=c;
    this->length+=1;
    return this;
}

// insert_cstr 函数实现
string _string_insert_cstr(string this,size_t pos,const char *s){
    size_t len=strlen(s);
    if(pos>this->length) pos=this->length;
    this->str=(char *)realloc(this->str,this->length+len+1);
    memmove(this->str+pos+len,this->str+pos,this->length-pos+1);
    memcpy(this->str+pos,s,len);
    this->length+=len;
    return this;
}

// insert_string 函数实现
string _string_insert_string(string this,size_t pos,string other){
    return _string_insert_cstr(this,pos,other->str);
}

// find_char 函数实现
size_t _string_find_char(string this,size_t pos,char c){
    if(pos>=this->length) return this->npos;
    char *p=strchr(this->str+pos,c);
    if(p) return p-this->str;
    else return this->npos;
}

// find_cstr 函数实现
size_t _string_find_cstr(string this,size_t pos,const char *s){
    if(pos>=this->length) return this->npos;
    char *p=strstr(this->str+pos,s);
    if(p) return p-this->str;
    else return this->npos;
}

// find_string 函数实现
size_t _string_find_string(string this,size_t pos,string other){
    return _string_find_cstr(this,pos,other->str);
}

// size 函数实现
size_t _string_size(string this){
    return this->length;
}

// length_func 函数实现
size_t _string_length_func(string this){
    return this->length;
}

// at 函数实现
char _string_at(string this,size_t pos){
    if(pos>=this->length) return '\0';
    return this->str[pos];
}

// clear 函数实现
void _string_clear(string this){
    free(this->str);
    this->str=(char *)malloc(1);
    this->str[0]='\0';
    this->length=0;
}

// empty 函数实现
int _string_empty(string this){
    return this->length==0;
}

// data 函数实现
const char *_string_data(string this){
    return this->str;
}

// 初始化 String 对象的函数
void string_init(string this){
    this->str=(char *)malloc(1);
    this->str[0]='\0';
    this->length=0;
    this->npos=(size_t)(-1);

    // 赋值函数指针
    this->c_str=_string_c_str;
    this->append_char=_string_append_char;
    this->append_cstr=_string_append_cstr;
    this->append_string=_string_append_string;
    this->insert_char=_string_insert_char;
    this->insert_cstr=_string_insert_cstr;
    this->insert_string=_string_insert_string;
    this->find_char=_string_find_char;
    this->find_cstr=_string_find_cstr;
    this->find_string=_string_find_string;
    this->size=_string_size;
    this->length_func=_string_length_func;
    this->at=_string_at;
    this->clear=_string_clear;
    this->empty=_string_empty;
    this->data=_string_data;
}

// 销毁 String 对象的函数
void string_destroy(string this){
    free(this->str);
    this->str=NULL;
    this->length=0;
}