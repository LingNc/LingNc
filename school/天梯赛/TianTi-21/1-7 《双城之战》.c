#include<stdio.h>
#include<string.h>
int main(){
    char name[1001]={0};
    gets(name);
    int n;
    scanf("%d",&n);
    getchar();
    int k=n;
    while(k--){
        char N[1001]={0};
        gets(N);
        if(strcmp(N,name)==0){
            printf("%d",n-k);
            break;
        }
    }
    return 0;
}