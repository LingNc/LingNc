#include<stdio.h>
int main(){
    int m,n;
    scanf("%d",&m);
    int A[m];
    for(int i=0;i<=m-1;i++)
        scanf("%d",&A[i]);
    scanf("%d",&n);
    int B[n];
    for(int i=0;i<=n-1;i++)
        scanf("%d",&B[i]);
    int C[m+n];
    int x=m-1,y=0,z=0;
    while(1){
        if(A[x]>B[y]){
            C[z]=A[x];
            if(x>0) x--;
            else A[x]=B[y];
        }
        else if(A[x]==B[y]){
            C[z]=A[x];
            if(x>0) x--;
            else A[x]=B[y];
        }
        else{
            C[z]=B[y];
            if(y<n-1) y++;
            else B[y]=A[x];
        }
        if(z<m+n-1) z++;
        else break;
    }
    for(int i=0;i<=m+n-1;i++)
        printf("%d ",C[i]);
    return 0;
}