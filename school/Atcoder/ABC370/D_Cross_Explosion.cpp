#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"Yes":"No")<<'\n'
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
typedef pair<char,int> PII;

const i32 N=0;

int dx[4]={ 1,0,-1,0 },dy[4]={ 0,1,0,-1 };
int H,W,Q;
// void pri(vector<vector<int>> &mp){
//     foe(i,1,mp.size()-1){
//         foe(j,1,mp[0].size()-1){
//             cout<<mp[i][j]<<' ';
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }
bool f(vector<vector<int>> &mp,int x,int y,int opt){
    while(1){
        x+=dx[opt],y+=dy[opt];
        if(x>H||x<1||y<1||y>W) break;
        if(mp[x][y]==0) continue;
        if(mp[x][y]==1){
            mp[x][y]=0;
            return true;
        }
    }
    return false;
}
void solve(){
    cin>>H>>W>>Q;
    vector<vector<int>> mp(H+1,vector<int>(W+1,1));
    int r,c;
    int ans=H*W;
    foe(i,1,Q){
        cin>>r>>c;
        if(mp[r][c]==1){
            ans--;
            mp[r][c]=0;
        }
        else{
            foe(j,0,3){
                if(f(mp,r,c,j)){
                    ans--;
                    // pri(mp);
                }
            }
        }
    }
    cout<<ans<<endl;

}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}