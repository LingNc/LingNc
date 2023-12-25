#include<stdio.h>
void convert(int n);
int main(){
    int n;
    scanf("%d",&n);
    convert(n);
    return 0;
}
void convert(int n){
    if(n>0){
        convert(n/2);
        printf("%d",n%2);;
    }
}