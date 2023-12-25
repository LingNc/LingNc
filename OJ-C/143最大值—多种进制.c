#include<stdio.h>
#include<string.h>
int KToD(char str[],int k);
int main(){
    int n;
    scanf("%d",&n);
    struct{
        char num[33];
        char ck[2];
        int k;
        int d10;
    }str[n];
    for(int i=0;i<=n-1;i++){
        scanf("%s%s",&str[i].num,&str[i].ck);
        if(str[i].ck[1]=='0')
            str[i].k=10;
        else
            str[i].k=str[i].ck[0]-'0';
        str[i].d10=KToD(str[i].num,str[i].k);
    }
    int max=str[0].d10;
    for(int i=1;i<=n-1;i++)
        if(str[i].d10>max)
            max=str[i].d10;
    printf("%d",max);
    return 0;
}
int KToD(char str[],int k){
    int n=strlen(str),sum=0;
    for(int i=0;i<=n-1;i++)
        sum=k*(str[i]-'0'+sum);
    return sum/k;
}