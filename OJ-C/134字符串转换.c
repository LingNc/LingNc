#include<stdio.h>
#include<string.h>
void del(char str[],int n,int k);
int main(){
    char str[100];
    gets(str);
    int n=strlen(str);
    for(int i=0;i<=n-1;i++){
        if(str[i]<'0'||str[i]>'9'){
            del(str,n,i);
            n--;
            i--;
        }
    }
    int num=0;
    for(int i=0;i<=n-1;i++)
        num=10*(num+str[i]-'0');
    num/=10;
    printf("%d",2*num);
    return 0;
}
void del(char str[],int n,int k){
    for(int i=k;i<=n-1;i++)
        str[i]=str[i+1];
}