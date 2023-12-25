#include<stdio.h>

void del(int a[],int n,int k);
void sort(int a[],int n);

int main(){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<=N-1;i++)
        scanf("%d",&a[i]);
    sort(a,N);
    for(int i=0;i<=N-2;i++)
        if(a[i]==a[i+1]){
            del(a,N,i);
            N--;
            i--;
        }
    printf("%d\n",N);
    for(int i=0;i<=N-1;i++)
        printf("%d ",a[i]);
    return 0;
}
void sort(int a[],int n){
    for(int i=0;i<=n-2;i++){
        for(int i=0;i<=n-2;i++){
            if(a[i]>a[i+1]){
                int t;
                t=a[i];a[i]=a[i+1];a[i+1]=t;
            }
        }
    }
}
void del(int a[],int n,int k){
    for(int i=k;i<=n-2;i++)
        a[i]=a[i+1];
    a[n-1]=-1;
}