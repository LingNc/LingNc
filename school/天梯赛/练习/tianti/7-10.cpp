#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
typedef pair<int,int> PII;

int bigger(vector<PII> &a,int num){
    int l=0,r=a.size();
    while(l+1<r){
        int mid=(l+r)>>1;
        if(a[mid].second>=num) r=mid;
        else l=mid;
    }
    return r;
}

void solve(){
    int n;
    cin>>n;
    int opt,price,time;
    vector<PII> a;
    int cost=0;
    map<PII,int> mp;
    foe(i,0,n){
        cin>>opt>>price>>time;
        if(opt==0){
            a.push_back({ price,time });
            cost+=price;
            mp[{price,time}]=1;
        }
        else{
            int l=bigger(a,time-45);
            int k=0;
            PII max_num;
            bool is_free=false;
            foe(i,l,a.size()){
                if(mp[a[i]]==1){
                    k++;
                    if(a[i].first>=price){
                        is_free=true;
                        mp[a[i]]=0;
                    }
                }
            }

        }
    }
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}