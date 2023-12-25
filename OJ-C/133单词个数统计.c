#include<stdio.h>
#include<string.h>
int main(){
    char str[1000];
    gets(str);
    int n=strlen(str);
    str[n]=' ';
    str[n+1]='\0';
    int word_num=0;
    for(int i=0;i<=n-1;i++){
        if(str[i]!=' '&&str[i+1]==' ')
            word_num++;
    }
    printf("%d",word_num);
    return 0;
}
