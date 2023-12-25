#include<stdio.h>
int main(){
    int n,Y[100][100]={0};
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++)
        Y[i][1]=1;
    for(int i=1;i<=n-1;i++)
        for(int j=2;j<=i+1;j++)
            Y[i][j]=Y[i-1][j-1]+Y[i-1][j];
    for(int i=0;i<=n-1;i++){
        for(int j=1;j<=i+1;j++)
            printf("%d ",Y[i][j]);
        printf("\n");
    }
    return 0;
}