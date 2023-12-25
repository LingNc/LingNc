#include<stdio.h>
#include<string.h>
int main(){
    char list[100001]={0};
    scanf("%s",list);
    int len=strlen(list);
    for(int i=0;i<=len-1;i++){
        list[i]=(2*(list[i]-'a')+1)%26+'a';
    }
    puts(list);
    return 0;
}