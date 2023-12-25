#include<stdio.h>
#include<string.h>
int bToD(char str[]);
int main(){
    typedef struct{
        char bit[31];
        int num;
    }str;
    str arr[3];
    scanf("%s%s%s",&arr[0].bit,&arr[1].bit,&arr[2].bit);
    for(int i=0;i<=2;i++)
        arr[i].num=bToD(arr[i].bit);
    for(int k=0;k<=1;k++){
        for(int i=0;i<=1;i++)
            if(arr[i].num>arr[i+1].num){
                str t=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=t;
            }
    }
    for(int i=0;i<=2;i++)
        printf("%d ",arr[i].num);
    return 0;
}
int bToD(char str[]){
    int n=strlen(str),sum=0;
    for(int i=0;i<=n-1;i++)
        sum=2*(str[i]-'0'+sum);
    return sum/2;
}
