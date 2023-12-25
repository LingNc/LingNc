#include<stdio.h>

void del(int a[],int n,int i);  /*删除数组a中下标为i的元素*/
void PrintArr(int a[],int n); /*输出数组a的前n个元素*/
int find(int a[],int n,int x);

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<=n-1;i++)
        scanf("%d",&a[i]);

    int x;
    scanf("%d",&x);
    if(find(a,n,x)!=-1)
        x=find(a,n,x);
    else{
        printf("Not Found");
        return 0;
    }

    del(a,n,x);
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
            printf("%4d",a[i]);
}
int find(int a[],int n,int x){
    int flag=-1;
    for(int i=0;i<=n-1;i++)
        if(a[i]==x){
            flag=i;
            break;
        }
    if(flag==-1)
        return -1;
    else
        return flag;
}