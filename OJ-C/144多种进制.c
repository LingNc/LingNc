#include<stdio.h>
void dToK(int n,int k,char str[]);
int main(){
    int num[]={2,3,7,8};
    int n;
    scanf("%d",&n);
    for(int i=0;i<=3;i++){
        char str[33]={'\0'};
        dToK(n,num[i],str);
        printf("%s\n",str);
    }
    return 0;
}
void dToK(int n,int k,char str[]){
    int num=n,i=0;
    for(i;i<=32;i++){
        if(i!=0) num/=k;
        if(num==0) break;
        str[i]=num%k+'0';
    }
    num=--i;
    for(int j=0;j<=num/2;j++){
        char t=str[i];
        str[i]=str[j];
        str[j]=t;
        i--;
    }
}