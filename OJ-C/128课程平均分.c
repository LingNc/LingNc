#include<stdio.h>
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    double Course[m][n];

    for(int i=0;i<=m-1;i++)
        for(int j=0;j<=n-1;j++)
            scanf("%lf",&Course[i][j]);

    for(int i=0;i<=n-1;i++){
        double sum=0;
        for(int j=0;j<=m-1;j++)
            sum+=Course[j][i];
        printf("%.2lf ",sum/m);
    }
    return 0;
}