#include "exception.h"
#include "tools.h"
// #include <stddef.h>
#include <string.h>
#include <stdlib.h>
#ifndef STRING_H

// 动态字符串拼接函数
string nstrcat(const string _str1,const string _str2){
    if(_str1==NULL) return _str2;
    if(_str2==NULL) return _str1;
    size_t str1_len=strlen(_str1);
    size_t str2_len=strlen(_str2);
    size_t new_size=str1_len+str2_len+1;
    string temp_str=malloc(new_size*sizeof(char));
    if(temp_str==NULL) return NULL;
    // 拼接
    strcpy(temp_str,_str1);
    strcat(temp_str,_str2);
    return temp_str;
}
string strapp(string _dest,const string _str){
    if(_dest==NULL) return _str;
    if(_str==NULL) return _dest;
    size_t dest_len=strlen(_dest);
    size_t str_len=strlen(_str);
    size_t new_size=dest_len+str_len+1;
    string temp_str=realloc(_dest,new_size*sizeof(char));
    if(temp_str==NULL) return NULL;
    // 拼接
    strcat(temp_str,_str);
    return temp_str;
}
#endif

// 状态退化函数
status status_down(status *self,status new_status){
    if(new_status<*self) *self=new_status;
    return *self;
}

// 异常处理

Exception new_exception(status status,string msg){
    Exception self;
#   ifndef STRING_H
    string temp_str=nstrcat(to_str(status)," ");
    temp_str=strapp(temp_str,msg);
    // 不能free字面量
    // status_down(&t, sfree(msg));
    self.msg=temp_str;
#   endif
    self.status=status;
    return self;
}

Exception exception_pass(exception self,Exception e){
    if(self==NULL){
        return new_exception(ERROR,"exception_add: 传入self指针为空!");
    }
    status res=SUCCESS;
    // 异常降级
    status_down(&res,self->status);
    status_down(&res,e.status);
    // 计算大小
#   ifndef STRING_H
    size_t msgSize=strlen(self->msg);
    size_t next_msgSize=strlen(e.msg);
    size_t new_size=msgSize+next_msgSize+2;
    // 使用calloc保证配置后字符串初始化为0
    string temp_str=calloc(new_size,sizeof(char));
#   endif

    // 黏贴
#   ifndef STRING_H
    strcat(temp_str,self->msg);
    if(msgSize!=0&&next_msgSize!=0) strcat(temp_str,"\n");
    strcat(temp_str,e.msg);
#   endif
    self->status=res;
    self->msg=temp_str;
    return *self;
}

Exception exception_catch(exception self,Exception e){
    if(self==NULL){
        return new_exception(ERROR,"exception_catch: 传入self指针为空!");
    }
    // 异常降级
    status res=SUCCESS;
    status_down(&res,self->status);
    status_down(&res,e.status);
    // 计算大小
#   ifndef STRING_H
    size_t msgSize=strlen(self->msg);
    size_t next_msgSize=strlen(e.msg);
    size_t new_size=msgSize+next_msgSize+2;
    string temp_str=calloc(new_size,sizeof(char));
#   endif
    // 黏贴
#   ifndef STRING_H
    strcat(temp_str,e.msg);
    if(msgSize!=0&&next_msgSize!=0) strcat(temp_str," --> \n");
    strcat(temp_str,self->msg);
#   endif
    self->status=res;
    self->msg=temp_str;
    return *self;
}

status exception_get(exception self){
    return self->status;
}

Exception exception_down(exception self,status new_status){
    if(self==NULL){
        return new_exception(ERROR,"exception_add: 传入self指针为空!");
    };
    status_down(&self->status,new_status);
    return new_exception(self->status,self->msg);
}

status free_exception(exception self){
    status res=SUCCESS;
    if(self==NULL) status_down(&res,WARRING);
    else status_down(&res,sfree(self->msg));
    status_down(&res,sfree(self));
    return res;
}