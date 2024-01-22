#include<iostream>
#include<cstdio>
using namespace std;
int num[(int)1e6+1];
int my_find(int *num,int len,int k);
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n-1;i++){
        scanf("%d",&num[i]);
    }
    int k;
    for(int i=1;i<=m;i++){
        scanf("%d",&k);
        printf("%d ",my_find(num,n,k)+1);
    }
    return 0;
}
int my_find(int *num,int len,int k){
    int start=-1,end=len,mid=-1;
    while(start+1!=end){
        mid=((start+end)>>1);
        if(num[mid]<k)
            start=mid;
        else
            end=mid;
    }
    return (num[end]==k)?end+1:-1;
}
