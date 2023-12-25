#include<stdio.h>
#include<string.h>
void convert(int n,char str[]);
int main(){
    char b[32]={'\0'};
    int num;
    scanf("%d",&num);
    convert(num,b);
    int n=strlen(b);
    for(int i=n-1;i>=0;i--)
        printf("%c",b[i]);
    return 0;
}
void convert(int n,char str[]){
    int num=n,i=0;
    str[i]='0';
    while(1){
        if(num>0){
            str[i]=num%2+'0';
            i++;
            num/=2;
        }
        else
            break;
    }
}