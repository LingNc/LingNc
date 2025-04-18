#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
typedef pair<int,int> PII;
#define all(a) a.begin(),a.end()

bool is_prime(int x){
    if(x<=3) return (x==1)?false:true;
    int sq=sqrt(x);
    foe(i,2,sq+1){
        if(x%i==0) return false;
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> in;
    int max_lenth=-1;
    int res_start=0;
    int sq=sqrt(n);
    if(is_prime(n)){
        cout<<1<<endl;
        cout<<n<<endl;
        return;
    }
    foe(i,2,sq+1){
            int sum=1;
        for(int j=i;sum*j<=n;j++){
            sum*=j;
            if(j-i+1>max_lenth&&n%sum==0){
                max_lenth=j-i+1;
                res_start=i;
            }
            if(n%sum!=0) break;
        }
    }
    cout<<max_lenth<<endl;
    foe(i,res_start,max_lenth+res_start){
        if(i!=res_start) cout<<'*';
        cout<<i;
    }
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}