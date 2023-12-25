#include<stdio.h>
#include<string.h>
int check(int num_1[],int n_1,int num_2[],int n_2,int k);
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int A[m],B[n];
    for(int i=0;i<=m-1;i++)
        scanf("%d",&A[i]);
    for(int i=0;i<=n-1;i++)
        scanf("%d",&B[i]);
    int l=0,k;
    for(int i=0;i<=m-1;i++){
        if(A[i]==B[0]){
            l=check(A,m,B,n,i);
            if(l){
                k=i;
                break;
            }
        }
    }
    if(l) printf("%d",k);
    else printf("No Answer");
    return 0;
}
int check(int num_1[],int n_1,int num_2[],int n_2,int k){
    if(n_1<k+n_2) return 0;
    int flag=0;
    for(int i=k;i<=k+n_2-1;i++){
        if(num_1[i]==num_2[i-k])
            flag++;
    }
    if(flag==n_2) return 1;
    else return 0;
}