#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    int sum=0;
    while(1){
        char n[50]={0};
        scanf("%s",n);
        char ch=getchar();
        if(n[0]=='-'||isdigit(n[0])){
            sum+=atoi(n);
        }
        if(ch=='\n') break;
    }
    printf("%d\n",sum);
    return 0;
}