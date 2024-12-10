#include <stdio.h>
#include <stdlib.h>

#define string char
#include<ctype.h>
void WriteLetter(FILE *f){

    string str[100];
    scanf("%s",str);
    int i=0;
    while(1){
        if(str[i]==0) break;
        str[i]=toupper(str[i]);
        i++;
    }
    fprintf(f,"%s",str);
}

int main(){
    FILE *f;
    f=fopen("Letter.txt","w");
    if(!f){
        puts("文件无法打开!");
        exit(1);
    }

    WriteLetter(f);

    if(fclose(f)){
        puts("文件无法关闭!");
        exit(1);
    }
    puts("文件保存成功!");
    return 0;
}

/* 你提交的代码将被嵌在这里 */