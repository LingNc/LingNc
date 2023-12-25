#include<stdio.h>
void PrintArr(int a[],int n);
void sort(int a[],int n);

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<=n-1;i++)
        scanf("%d",&a[i]);
    sort(a,n);
    PrintArr(a,n);
    return 0;
}
void PrintArr(int a[],int n){
    if(n!=0)
        for(int i=0;i<=n-1;i++)
            printf("%d ",a[i]);
}
void sort(int a[],int n){
    for(int j=0;j<=n-2;j++){
        for(int i=0;i<=n-2;i++){
            if(a[i]>a[i+1]){
                int t;
                t=a[i];a[i]=a[i+1];a[i+1]=t;
            }
        }
    }
}