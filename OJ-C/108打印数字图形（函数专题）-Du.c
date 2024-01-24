#include<stdio.h>
void PrintSpace(int m){
    while(m--) printf(" ");
}
void PrintDigit(int m){
    int i,j;
    for(i=1;i<=m;i++){
        printf("%d",i);
    }
    for(j=m-1;j>=1;j--){
        printf("%d",j);
    }
}
int main(){
    int n,x=1,y;
    scanf("%d",&n);
    for(int j=1;j<=n;j++){
        PrintSpace((2*n-1-x)/2);
        PrintDigit(j);
        x+=2;
        printf("\n");
    }
    y=x-4;
    for(int i=n-1;i>=1;i--){
        PrintSpace((2*n-1-y)/2);
        PrintDigit(i);
        y-=2;
        printf("\n");
    }

    return 0;
}
