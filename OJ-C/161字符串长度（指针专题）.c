#include<stdio.h>

int len(char* sp);
int main(){
    char str[101]={0};
    scanf("%[^\n]%*c",str);
    printf("%d\n",len(str));
    return 0;
}
int len(char* sp){
    //实现sp所指串的长度，不计空格。
    int l=0;
    char* p=sp;
    while(1){
        if(*p==0) break;
        if(*p!=' '){
            l++;
        }
        p++;
    }
    return l;
}