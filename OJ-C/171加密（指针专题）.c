#include<stdio.h>
#include<string.h>
void encrypt(char *plain,char *cipher);
void reverse(char* str);
int main(){
    char plain[201]={0},cipher[601]={0};
    scanf("%s",plain);
    encrypt(plain,cipher);
    reverse(cipher);
    puts(cipher);
    return 0;
}
//加密:将每个字符的ascii码的值减去24作为每个字符加密后的值
//把原文字符串plain加密后存入字符串cipher
void encrypt(char *plain,char *cipher){
    int len=strlen(plain);
    for(int i=0;i<=len-1;i++){
        char ch=plain[i]-24;
        cipher[2*i]=ch/10+'0';
        cipher[2*i+1]=ch%10+'0';
    }
}
//逆转
void reverse(char* str){
    int len=strlen(str);
    for(int i=0;i<=(len-1)/2;i++){
        char t=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]=t;
    }
}