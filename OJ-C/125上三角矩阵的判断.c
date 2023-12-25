#include<stdio.h>
int N=10;

int IsUpperTriMatrix(int a[][N], int n);

int main(){
    int n=4;
    scanf("%d",&n);
    int a[n][N];
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(IsUpperTriMatrix(a,n))
        printf("YES");
    else
        printf("NO");
    return 0;
}
int IsUpperTriMatrix(int a[][N], int n){
    int flag=0,m=n/2-1;
    for(int i=m;i>=0;i--){
        for(int j=m;j>=0;j--){
            if(a[i+1][j]!=0){
                flag++;
                goto end;
            }
        }
        m--;
    }
    end:
    if(flag!=0) return 0;
    else return 1;
}