#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define int long long
using i64=long long;
using namespace std;

const int N=1e5+10;

void solve(){
    ofstream file;
    default_random_engine e;
    uniform_int_distribution<int> u(0,10000); // 左闭右闭区间
    e.seed(time(0));

    file.open("test.txt");
    for(int i=1; i<=1e6; i++){
        int s=u(e);
        if(s%2==0){
            file<<s<<' ';
        }
        else{
            i--;
        }
    }
    file.close();
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}