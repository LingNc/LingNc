#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        char str[102];
        gets(str);
        int len=strlen(str);
        int n=str[len-1]-'0';
        char* p=strchr(str,'.');
        int num=*(p+n);
        if(n>len-4||num<'0'||num>'9') num='0';
        printf("%d\n",num-'0');
    }
    return 0;
}
