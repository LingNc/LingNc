#include<stdio.h>
#include<string.h>
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int origin[m][n],after[n][m];
    memset(origin,0,sizeof(origin));
    memset(after,0,sizeof(after));
    int* p=&origin[0][0];
    for(int i=0;i<=m*n-1;i++){
        scanf("%d",p);
        p++;
    }
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            printf("%d ",origin[j][i]);
        }
        putchar('\n');
    }
    return 0;
}
