#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
#define endl '\n'

using namespace std;
int prime(int n);
int main(){
    int m,n;
    cin>>m>>n;
    int p,q,r;
    int pri[n-m+1];
    memset(pri,0,sizeof(pri));
    int k=0;
    foe(i,m,n){
        if(prime(i)){
            pri[k]=i;
            k++;
        }
    }
    int num=0;
    foe(p,0,k-1)
        foe(q,p+1,k-1)
            foe(r,q+1,k-1){
                if(prime(pri[p]*pri[q]+pri[r])&&prime(pri[q]*pri[r]+pri[p])&&prime(pri[r]*pri[p]+pri[q])){
                    num++;
                }
            }
    cout<<num<<endl;
    return 0;
}
int prime(int n){
    int sq=sqrt(n);
    if(n<=3) return (n>=2)?1:0;
    for(int i=2;i<=sq;i++)
        if(n%i==0) return 0;
    return 1;
}