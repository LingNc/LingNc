#include <stdio.h>

int main(void){
    int n,m;
    double arr[1000][10]={0};
    double brr[1000]={0};

    scanf("%d %d",&m,&n);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%lf",&arr[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            brr[i]+=arr[j][i];
        }
        brr[i]/=m;
        printf("%.2f ",brr[i]);
    }

    return 0;
}