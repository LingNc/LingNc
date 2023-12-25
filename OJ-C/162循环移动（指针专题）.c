#include<stdio.h>
#include<string.h>
void ringShift(int* a,int n,int k);
void ringOne(int *a,int n);
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    memset(a,0,n*sizeof(int));
    for(int i=0;i<=n-1;i++){
        scanf("%d",&a[i]);
    }
    int k;
    scanf("%d",&k);
    ringShift(a,n,k);
    for(int i=0;i<=n-1;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
void ringShift(int* a,int n,int k){
    //循环移动后的数值仍然存入数组a中
    for(int i=1;i<=k;i++){
        ringOne(a,n);
    }
}
void ringOne(int *a,int n){
    int t=a[n-1];
    for(int i=n-1;i>=1;i--){
        a[i]=a[i-1];
    }
    a[0]=t;
}