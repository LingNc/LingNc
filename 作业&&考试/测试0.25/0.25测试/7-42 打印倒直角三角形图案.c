#include<stdio.h>
void prn(int n,int m){
    for(int j=1;j<=m-n;j++) printf(" ");
    for(int i=1;i<=n;i++) printf("*");
    printf("\n");
}
int main(){
    int m;
    scanf("%d",&m);
    for(int i=m;i>=1;i--) prn(i,m);
    return 0;
}
