#include<stdio.h>
void insert(int num[],int n,int number);
int main(){
    int m,n;
    //read in A[]
    scanf("%d",&m);
    int A[m];
    for(int i=0;i<=m-1;i++){
        scanf("%d",&A[i]);
    }
    //insert A
    scanf("%d",&n);
    int B[m+n];
    for(int i=0;i<=m-1;i++)
        B[i]=A[i];
    int k=m;
    for(int i=1;i<=n;i++){
        int number;
        scanf("%d",&number);
        insert(B,k,number);
        k++;
    }
    //print A
    for(int i=0;i<=m+n-1;i++){
        printf("%d ",B[i]);
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
        num[i+1]=num[i];
    }
    num[k]=number;
}
