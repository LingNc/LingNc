#include<stdio.h>
#include<string.h>
void ex(char str[]);
void plus(char A[],char B[],char result[]);
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char A[1000]={0},B[1000]={0},C[1000]={0};
        scanf("%s%s",&A,&B);
        ex(A);ex(B);
        plus(A,B,C);
        ex(C);
        printf("%s\n",C);
    }
    return 0;
}
void plus(char A[],char B[],char result[]){
    int i=999;
    for(int i=0;i<=999;i++){
        if(A[i]>='0'&&A[i]<='9')
            A[i]-='0';
        if(B[i]>='0'&&B[i]<='9')
            B[i]-='0';
    }
    while(i){
        result[i]+=A[i]+B[i];
        while(result[i]>9){
            result[i-1]++;
            result[i]-=10;
        }
        i--;
    }
    int flag=0;
    for(int i=0;i<=999;i++){
        if(result[i]==0&&result[i+1]!=0&&flag==0){
            flag=1;
            continue;
        }
        if(flag)
            result[i]+='0';
    }
}
void ex(char str[]){
    if(str[0]==0){
        int n=0;
        for(int i=999;i>=0;i--){
            if(str[i]!=0&&str[i-1]==0){
                n=1000-i;
                break;
            }
        }
        for(int i=999;i>=0;i--){
            n--;
            if(n<0) break;
            str[n]=str[i];
            str[i]=0;
        }
    }
    else{
        int n=strlen(str)-1;
        for(int i=999;i>=0;i--){
            str[i]=str[n];
            str[n]=0;
            n--;
            if(n<0) break;
        }
    }
}