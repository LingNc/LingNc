#include<stdio.h>
int main(){
    char ch;
    scanf("%c",&ch);
    if(ch>='a'&&ch<='z') printf("lower");
    else if(ch>='A'&&ch<='Z') printf("upper");
    else if(ch>='0'&&ch<='9') printf("digit");
    else printf("other");
    return 0;
}