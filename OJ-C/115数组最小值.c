#include<stdio.h>
int min_arr(int a[],int size);

int main(){
    int n,num;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<=n-1;i++){
        scanf("%d",&num);
        a[i]=num;
    }
    int min=min_arr(a,n),x=0;
    for(int i=0;i<=n-1;i++)
        if(a[i]==min){
            x=i;
            break;
        }
    printf("%d %d",min,x);
    return 0;
}
int min_arr(int a[],int size){
    int min=a[0];
    for(int i=1;i<=size-1;i++){
        if(a[i]<min)
            min=a[i];
    }
    return min;
}