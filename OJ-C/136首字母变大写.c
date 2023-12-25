#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    gets(str);
    int n=strlen(str);
    for(int i=n;i>=0;i--)
        str[i+1]=str[i];
    str[0]=' ';
    for(int i=0;i<=n;i++)
        if(str[i]==' '&&str[i+1]!=' '&&str[i+1]>='a'&&str[i+1]<='z')
            str[i+1]-=32;
    for(int i=1;i<=n;i++)
        printf("%c",str[i]);
    return 0;
}