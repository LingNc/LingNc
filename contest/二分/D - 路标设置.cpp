#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool check(int x);
int L,N,K;
int sign[100000+10]={0};
int main(){
    cin>>L>>N>>K;
    for(int i=0;i<=N-1;i++){
        cin>>sign[i];
    }
    int l=-1,r=L+1,mid;
    while(l+1!=r){
            mid=(l+r)>>1;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    cout<<r<<'\n';
    return 0;
}
bool check(int x){
    if(x==0) return 1;
    int num=0,n;
    for(int i=1;i<=N-1;i++){
        n=sign[i]-sign[i-1];
        num+=n/x;
        num-=(n%x==0)?1:0;
    }
    return num>K;
}
