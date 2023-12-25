#include<stdio.h>
int m,p,n;
int main(){
    scanf("%d %d %d",&m,&p,&n);
    int A[m][p],B[p][n],C[m][n];
    for(int i=0;i<=m-1;i++)
        for(int j=0;j<=p-1;j++)
            scanf("%d",&A[i][j]);
    for(int i=0;i<=p-1;i++)
        for(int j=0;j<=n-1;j++)
            scanf("%d",&B[i][j]);
    for(int i=0;i<=m-1;i++){
        for(int j=0;j<=n-1;j++){
            int sum=0;
            for(int b=0;b<=p-1;b++)
                sum+=A[i][b]*B[b][j];
            C[i][j]=sum;
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
