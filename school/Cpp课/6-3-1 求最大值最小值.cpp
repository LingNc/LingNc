#include<stdio.h>
#define N 10
void maxmin(int arr[],int *pt1,int *pt2,int n);
int main(){
    int array[N]={ 10,7,19,29,4,0,7,35,-16,21 },*p1,*p2,a,b;
    p1=&a;p2=&b;
    maxmin(array,p1,p2,N);
    printf("max=%d,min=%d",a,b);
    return 0;
}


void maxmin(int arr[],int *pt1,int *pt2,int n){
    int max_res=-1,min_res=99999999;
    for(int i=1;i<=n-1;i++){
        if(arr[i]>max_res)
            max_res=arr[i];
        if(arr[i]<min_res)
            min_res=arr[i];
    }
    *pt1=max_res;
    *pt2=min_res;
}