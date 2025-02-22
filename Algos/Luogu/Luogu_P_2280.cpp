#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
#define fod(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
// using namespace std;
using string=std::string;
typedef std::vector<int> arr;
typedef std::pair<int,int> PII;

const i32 N=5e3+10;
typedef std::vector<std::vector<int>> Map;

void print(Map &map){
    foe(i,0,map.size()){
        foe(j,0,map.size()){
            std::cout<<map[i][j]<<' ';
        }
        std::cout<<endl;
    }
}

void solve(){
    int n,m;
    std::cin>>n>>m;
    Map map(N,std::vector<int>(N,0));
    int x,y,val;
    foe(i,0,n){
        std::cin>>x>>y>>val;
        map[x+1][y+1]+=val;
    }
    // print(map);
    Map pre_map(N,std::vector<int>(N,0));
    foe(i,1,N){
        foe(j,1,N){
            pre_map[i][j]=map[i][j]+pre_map[i-1][j]+pre_map[i][j-1]-pre_map[i-1][j-1];
        }
    }
    // print(pre_map);
    int res=0;
    foe(i,m,N){
        foe(j,m,N){
            int temp=pre_map[i][j]-pre_map[i-m][j]-pre_map[i][j-m]+pre_map[i-m][j-m];
            res=std::max(res,temp);
        }
    }
    std::cout<<res<<endl;
}
i32 main(){
    std::IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}