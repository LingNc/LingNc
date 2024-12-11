#include<stdio.h>
#include"String.h"
// #include"String.c"
int main(){
    String str;
    string_init(&str);
    char c[1000]={ 0 };
    scanf("%s",c);
    str.append_cstr(&str,c);
    char* res=str.c_str(&str);
    printf("%s",res);
    string_destroy(&str);
    return 0;
}