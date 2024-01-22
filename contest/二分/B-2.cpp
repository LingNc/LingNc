#include<cstdio>
#include<iostream>

using namespace std;
const int N=50010;
int num[N];
int panduan(int x,int m,int n){
    int cnt=0,s=0;
    for(int i=1;i<=n;i++){
        if(num[i]-s<x)//x大，需要移走num[i];
            cnt++;
        else
            s=num[i];//跳过去 
    }
    if(cnt<=m)
        return 0;
    else
        return 1;

}

int main(){
    int L,n,m;
    scanf("%d%d%d",&L,&n,&m);
    num[0]=0;

    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);

    num[n+1]=L;
    int l=0,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(panduan(mid,m,n))//如果返回1，说明mid太大了，不合法，则正确区间在左边
            r=mid-1;
        else//反之，mid合法，右边区间存可能存在更合适的解，继续循环 
            l=mid;
    }
    printf("%d\n",l);
    return 0;
}