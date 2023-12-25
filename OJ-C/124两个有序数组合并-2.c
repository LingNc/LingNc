#include<stdio.h>

void insert(int a[],int n,int num);

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
    
    
    for(int i=0;i<=m;i++){
        printf("%d ",A[i]);
    }
    return 0;
}
void insert(int a[],int n,int num){
    int x;
    for(int i=0;i<=n-1;i++)
        if(a[i]>num){
            x=i;
            break;
        }
    int m,t;
    m=a[x];
    for(int i=x+1;i<=n;i++){
        t=m;
        m=a[i];
        a[i]=t;
    }
    a[x]=num;
}