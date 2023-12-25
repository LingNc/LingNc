#include<stdio.h>
int main(){
    char word[100];
    int i=0;
    while(1){
        char a;
        scanf("%c",&a);
        if(a!=32&&a>=65&&a<=90)
            a+=32;
        if(a!='\n'){
            word[i]=a;
            i++;
        }
        else
            break;
    }
    int num[128]={0};
    for(int j=0;j<=i;j++)
        num[word[j]]++;
    int max=0,local;
    for(int i=122;i>=97;i--){
        if(num[i]>=max){
            max=num[i];
            local=i;
        }
    }
    printf("%c",local);
    return 0;
}