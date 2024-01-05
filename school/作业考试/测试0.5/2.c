#include<stdio.h>
#include<string.h>
int main(){
    char word[100];
    gets(word);
    int n=strlen(word);
    for(int i=n-1;i>=0;i--){
        printf("%c",word[i]);
    }
    return 0;
}