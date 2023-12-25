#include<stdio.h>

void del(int a[],int n,int i);  /*删除数组a中下标为i的元素*/
void PrintArr(int a[],int n); /*输出数组a的前n个元素*/

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<=n-1;i++)
        scanf("%d",&a[i]);
    int remove;
    scanf("%d",&remove);
    del(a,n,remove);
    PrintArr(a,n-1);
    return 0;
}
void del(int a[],int n,int i){
    for(int j=i;j<=n-2;j++)
        a[j]=a[j+1];
    a[n-1]=0;
}
void PrintArr(int a[],int n){
    if(n!=0)
        for(int i=0;i<=n-1;i++)
            printf("%d ",a[i]);
}