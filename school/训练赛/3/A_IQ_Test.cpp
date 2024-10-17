#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;
vector<vector<char>> test(4,vector<char>(4));

bool total(int x,int y){
    int a=0,b=0;
    foe(i,x,x+1){
        foe(j,y,y+1){
            if(test[i][j]=='.') a++;
            else b++;
        }
    }
    if(a==3||b==3||a==4||b==4) return true;
    else return false;
}

void solve(){

    foe(i,0,3)foe(j,0,3){
        cin>>test[i][j];
    }
    bool ans=0;
    foe(i,0,2)foe(j,0,2){
        ans=total(i,j);
        if(ans){
            yes(ans);
            return;
        }
    }
    yes(ans);
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}