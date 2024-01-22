#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int L,n,k,a[N];
inline bool check(int mid){
    int ans=0;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]>mid){
            ans+=(a[i]-a[i-1])/mid;
            if((a[i]-a[i-1])%mid==0)ans--;
            if(ans>k)return 0;
        }
    }
    return 1;
}
signed main(){
    cin>>L>>n>>k;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int l=0,r=L,ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
}
