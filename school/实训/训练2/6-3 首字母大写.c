#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void CapitalizeTheFirstLetter(FILE *in,FILE *out);

int main(){
    FILE *in,*out;

    in=fopen("in.txt","r");
    out=fopen("out.txt","w");

    if(in&&out){
        CapitalizeTheFirstLetter(in,out);
    }
    else{
        puts("文件无法打开!");
    }

    if(in){
        fclose(in);
    }
    if(out){
        fclose(out);
        puts("文件保存成功!");
    }
    return 0;
}

#define string char
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#include<stdlib.h>
#include<string.h>
void CapitalizeTheFirstLetter(FILE *in,FILE *out){
    string line[10000]={ 0 };
    while(fgets(line,10000,in)){
        int len=strlen(line);
        foe(i,0,len-1){
            if(isalpha(line[i])){
                if(i==0||!isalpha(line[i-1])){
                    line[i]=toupper(line[i]);
                }
            }
        }
        fprintf(out,"%s",line);
    }
}