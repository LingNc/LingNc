#include<stdio.h>
void prn(int n,int m){
    for(int j=1;j<=n;j++) printf(" ");
    for(int i=1;i<=m;i++) printf("*");
    printf("\n");
}
void print(int m){
    int i,j=1;
    i=m;
    while (1){
        prn(i-1,2*j-1);
        i--;
        j++;
        if(i<=0) break;
    }
}
int main(){
    int m;
    while (scanf("%d",&m)!=EOF) print(m);   
    return 0;
}
