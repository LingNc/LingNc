#include<stdio.h>
#include<string.h>
void plusK(char* str,int K);
int main(){
    char str[101]={0};
    scanf("%[^\n]%*c",str);
    int K;
    scanf("%d",&K);
    plusK(str,K);
    puts(str);
    return 0;
}
void plusK(char* str,int K){
    int len=strlen(str);
    for(int i=0;i<=len-1;i++){
        if(str[i]>='a'&&str[i]<='z')
            str[i]=(str[i]-'a'+K%26)%26+'a';
        if(str[i]>='A'&&str[i]<='Z')
            str[i]=(str[i]-'A'+K%26)%26+'A';
    }
}