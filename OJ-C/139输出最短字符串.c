#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d\n",&n);
    char str[n][1000];
    for(int i=0;i<=n-1;i++)
        gets(str[i]);
    int len[n];
    for(int i=0;i<=n-1;i++)
        len[i]=strlen(str[i]);
    int min=len[n-1],k;
    for(int i=n-2;i>=0;i--){
        if(len[i]<=min){
            min=len[i];
            k=i;
        }
    }
    puts(str[k]);
    return 0;
}