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

bool is_good(int num){
    bool res=true;
    int nums[8]={ 0 };
    int k=0;
    while(num){
        nums[k++]=num%10;
        num/=10;
    }
    foe(i,0,k){
        if(nums[i]%2!=(i+1)%2){
            res=false;
            break;
        }
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    int sum=0;
    foe(i,1,n+1){
        if(is_good(i)){
            sum++;
        }
    }
    cout<<sum<<endl;
}
i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}