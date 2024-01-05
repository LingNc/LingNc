#include<stdio.h>
int main(){
    char ch;
    scanf("%c",&ch);
    if(ch=='I')
        printf("%d",2147483647);
    if(ch=='L')
        printf("%lld",9223372036854775807);
    return 0;
}