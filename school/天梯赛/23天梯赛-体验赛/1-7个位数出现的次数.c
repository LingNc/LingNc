#include<stdio.h>
#include<string.h>
int main(){
    char num[200]={'\0'};
    int n[10]={0};
    int b=0;
    scanf("%s %d",num,&b);
    int len=strlen(num);
    for(int i=0;i<len;i++){
        n[num[i]-'0']++;
    }
    printf("%d\n",n[b]);
    return 0;
}