#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void maxLenStr(char* str[],int n,int* max);
int main(){
    char str[100][81]={0};
    char *s[100]={NULL};
    int num=0;
    while(1){
        s[num]=str[num];
        scanf("%[^\n]%*c",str[num]);
        if(strcmp(str[num],"****")==0) break;
        num++;
    }
    int max;
    maxLenStr(s,num,&max);
    puts(s[max]);
    return 0;
}
//从字符串数组str中找出最长的一个字符串，并将其标存入形参指针max所指内存。
void maxLenStr(char* str[],int n,int* max){
    int m=-1;
    for(int i=0;i<=n-1;i++){
        int l=strlen(str[i]);
        if(l>m){
            m=l;
            *max=i;
        }
    }
}