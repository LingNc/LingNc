#include<stdio.h>
#include<string.h>
int main(){
    char word[1001]={'\0'};
    gets(word);
    for(int i=1001;i>=0;i--)
        word[i]=word[i-1];
    word[0]=' ';
    int flag=0;
    for(int i=0;i<=999;i++){
        if(word[i]==' '&&word[i+1]!=' ')
            flag++;
    }
    printf("%d",flag);
    return 0;
}