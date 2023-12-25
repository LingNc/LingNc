#include<stdio.h>

void insert(int a[],int n,int num);
void PrintArr(int a[],int n);

int main(){
    int n,a[1000]={0};
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++)
        scanf("%d",&a[i]);
    int x;
    scanf("%d",&x);
    insert(a,n,x);
    PrintArr(a,n+1);
    return 0;
}

void insert(int a[],int n,int num){
    int x;
    x=(a[0]>num)?0:1;
    for(int i=0;i<=n-1;i++)
        if(a[i]>num){
            x=i;
            break;
        }
    int t,m;
    t=a[x];
    for(int i=x+1;i<=n;i++){
        m=t;
        t=a[i];
        a[i]=m;
    }
    a[x]=num;
}

void PrintArr(int a[],int n){
    if(n!=0)
        for(int i=0;i<=n-1;i++)
            printf("%d ",a[i]);
}