#include<stdio.h>
void insert(int num[],int n,int number);
int main(){
    int m,n,A[1000000]={0};
    scanf("%d",&m);
    for(int i=0;i<=m-1;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int number;
        scanf("%d",&number);
        insert(A,m,number);
    }
    for(int i=0;i<=m+n-1;i++){
        printf("%d ",A[i]);
    }
    return 0;
}
void insert(int num[],int n,int number){
    int k;
    for(int i=0;i<=n-1;i++){
        if(number<=num[i]){
            k=i;
            break;
        }
    }
    for(int i=n-1;i>=k;i--){
        num[i]=num[i-1];
    }
    num[k]=number;
}
