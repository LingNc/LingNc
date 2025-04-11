#include<bits/stdc++.h>
using namespace std;
using i32=int;
using i64=long long;
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
using arr=vector<int>;
using PII=pair<int,int>;
#define endl '\n'
#define IOS std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int mod=1e9+7;
int pow(int a,int b){
    int res=1%mod,t=a;
    while(b){
        if(b&1) res=res*t%mod;
        t=t*t%mod;
        b>>=1;
    }
    return res;
}

bool is_good(int num){
    bool res=true;
    string snum=to_string(num);
    int total=snum.size();
    foe(start,1,total+1){
        int j=snum[total-start]-'0';
        if(start%2==j%2) res=true;
        else{
            res=false;
            break;
        }
    }
    return res;
}
int nums_lenth(int lenth){
    return  (lenth%2)
        ?pow(5,lenth)
        :4*pow(5,lenth-1);
}
int nums_pow(int x){
    if(!x) return 1;
    int res=0;
    foe(i,1,x+1){
        res+=nums_lenth(i);
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    string ss=to_string(n);
    int res=0;
    vector<int> a;
    foe(i,0,ss.size()){
        int j=ss[ss.size()-i-1]-'0';
        a.push_back(j);
    }
    foe(i,0,a.size()){
        int j=0;
        if(i%2){
            // 偶数
            j=(a[i]%2)
                ?(a[i]+1)/2
                :a[i]/2+1;
            if(i==a.size()-1) j--;
        }
        else{
            // 奇数
            j=(a[i]%2)
                ?a[i]/2+1
                :a[i]/2;
        }
        res+=j*nums_pow(i);
    }
    cout<<res<<endl;
}
i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}