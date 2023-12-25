#include<stdio.h>
#include<limits.h>
int main(){
    int m,n;
    //read in A[]
    scanf("%d",&m);
    int A[m];
    for(int i=0;i<=m-1;i++)
        scanf("%d",&A[i]);
    //read in B[]
    scanf("%d",&n);
    int B[n];
    for(int i=0;i<=n-1;i++)
        scanf("%d",&B[i]);
    int C[m+n],i=m-1,j=0;
    for(int k=0;k<=m+n-1;k++){
        if(A[i]>B[j]){
            if(i>=0){
                C[k]=A[i];
                A[i]=INT_MIN;
                if(i>0) i--;
            }
        }
        else
            if(j<=n-1){
                C[k]=B[j];
                B[j]=INT_MIN;
                if(j<n-1) j++;
            }
    }
    for(int i=0;i<=m+n-1;i++)
        printf("%d ",C[i]);
    return 0;
}