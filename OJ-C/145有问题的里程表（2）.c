#include<stdio.h>
#include<string.h>
int DToN(char num[]);
int main(){
    char num[10];
    scanf("%s",&num);
    printf("%d",DToN(num));
    return 0;
}
int DToN(char num[]){
    int sum=0,n=strlen(num);
    for(int i=0;i<=n-1;i++){
        if(num[i]>'4') num[i]--;
        if(i<=n-2)    
            sum=9*(num[i]-'0'+sum);
        else
            sum=num[i]-'0'+sum;
    }
    return sum;
}