#include<stdio.h>
void PrintDigit(int);
void PrintSpace(int);

int main(){
    int x;
    scanf("%d",&x);
    for(int i=1;i<=x;i++){
        PrintSpace(x-i);
        PrintDigit(i);
    }
    for(int i=1;i<=x-1;i++){
        PrintSpace(i);
        PrintDigit(x-i);
        }
    return 0;
}

void PrintDigit(int m){
    for(int i=1;i<=m;i++) printf("%d",i);
    for(int i=m-1;i>=1;i--) printf("%d",i);
    printf("\n");
}

void PrintSpace(int m){
    for(int i=1;i<=m;i++) printf(" ");
}