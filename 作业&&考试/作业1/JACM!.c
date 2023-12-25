#include<stdio.h>
#include<string.h>
int main(){
    char str[51]={'\0'};
    gets(str);
    int num[128]={0},n=strlen(str);
    for(int i=0;i<=n-1;i++)
        num[str[i]]++;
    int min;
    min=(num['a']>num['c'])?num['c']:num['a'];
    min=(num['m']>min)?min:num['m'];
    printf("%d",min);
    return 0;
}