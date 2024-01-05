#include<stdio.h>
void sort(long long int a[],int n);
int main(){
    int n;
    long long int h;
    scanf("%d %lld",&n,&h);
    long long int list[n];
    for(int i=1;i<=n;i++)
        scanf("%lld",&list[i]);
    sort(list,n);
    int flag=1;
    for(int i=1;i<=n-2;i++){
        if(list[i+1]-list[i]==list[1]-list[0]
            &&list[i]<=h)
            flag++;
        else{
            printf("像一直在被优化，没队要的是我");
            return 0;
        }
    }
    if(flag==n-1)
        printf("我要易大山啦!");
    return 0;
}
void sort(long long int a[],int n){
    for(int j=0;j<=n-2;j++){
        for(int i=0;i<=n-2;i++){
            if(a[i]>a[i+1]){
                long long int t;
                t=a[i];a[i]=a[i+1];a[i+1]=t;
            }
        }
    }
}