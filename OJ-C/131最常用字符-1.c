#include<stdio.h>
#include<string.h>
int main(){
    char word[100];
    gets(word);
    int n=strlen(word);
    for(int i=0;i<=n-1;i++){
        if(word[i]>=65&&word[i]<=90)
            word[i]+=32;
    }
    int num=0,max=0;
    for(int i=0;i<=n-1;i++){
        if(word[i]>=97&&word[i]<=122){
            
        }
    }
    return 0;
}