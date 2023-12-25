#include<stdio.h>
void PrintArr(int a[],int n);
int MinIndex(int a[],int n);  //函数返回数组a中最小元素的下标
int MaxIndex(int a[],int n);  //函数返回数组a中最大元素的下标

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<=n-1;i++)
        scanf("%d",&a[i]);
    
    int t,m;
    t=a[0];
    m=MinIndex(a,n);
    a[0]=a[m];
    a[m]=t;
    
    t=a[n-1];
    m=MaxIndex(a,n);
    a[n-1]=a[m];
    a[m]=t;

    PrintArr(a,n);
    return 0;
}
int MinIndex(int a[],int n){
    int min[2]={0};
    min[0]=a[0];
    for(int i=1;i<=n-1;i++){
        if(a[i]<min[0]){
            min[0]=a[i];
            min[1]=i;
        }
    }
    return min[1];
}
int MaxIndex(int a[],int n){
    int max[2]={0};
    max[0]=a[0];
    for(int i=1;i<=n-1;i++){
        if(a[i]>max[0]){
            max[0]=a[i];
            max[1]=i;
        }
    }
    return max[1];
}

void PrintArr(int a[],int n){
    if(n!=0)
        for(int i=0;i<=n-1;i++)
            printf("%d ",a[i]);
}