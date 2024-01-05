#include<stdio.h>
int vowel(char ch);
int main(){
    char ch;
    int count=0;
    while(scanf("%c",&ch),ch!='\n'){
        if(vowel(ch))
            count++;
    }
    printf("%d\n",count);
}

int vowel(char ch){
    char vow[10]="aAeEiIoOuU";
    char flag=0;
    for(int i=0;i<=9;i++){
        if(ch==vow[i])
            return 1;
    }
    return 0;
}