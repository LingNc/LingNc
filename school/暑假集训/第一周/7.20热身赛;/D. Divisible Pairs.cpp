#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define int long long
using i64=long long;
using namespace std;

// const int N=1e5+10;
typedef pair<int,int> PII;
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> arr(n,0);
    foe(i,0,n-1) cin>>arr[i];
    map<PII,int> mp;
    int sum=0;
    foe(i,0,n-1){
        int k=arr[i];
        int s1=(x-k%x)%x,s2=k%y;
        sum+=mp[{s1,s2}];
        mp[{k%x,k%y}]++;
    }
    cout<<sum<<endl;
}
signed main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
我们设 s1=ai，s2=aj​。如果 s1+s2≡0(mod x)，那么很容易发现，如果确定了 s1，那么满足条件的 s2 一定满足 s2 mod x=(x−s1 mod x) mod x，s2 mod y=s1 mod y。因为只有这样，才是满足要求的数对。

这样，我们就可以从 n 到 1 每次枚举一个 ai​，使用 map 存储取模 x,y 的情况，这样就可以求出在 ai​ 之后满足条件的 aj​ 的数量，将它加到答案里。
*/