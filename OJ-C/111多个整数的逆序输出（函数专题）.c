#include<stdio.h>
void inverse(int);
int main(){
    int n;
    scanf("%d",&n);
    inverse(n);
    return 0;
}
void inverse(int n){
    int num;
    scanf("%d",&num);
    if(n>1){
        inverse(n-1);
        printf("%d ",num);
    }
    else
        printf("%d ",num);
} 