#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"Yes":"No")<<'\n'
#define foe(i,a,b) for(size_t i=(a);i<=(b);i++)
#define fod(i,a,b) for(size_t i=(a);i>=(b);i--)
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
int dx[]={ -1,0,1,0 },dy[]={0,1,0,-1};


void solve(){
    int H,W,X,Y;
    cin>>H>>W>>X>>Y;
    vector<vector<char>> mp(H+1,vector<char>(W+1));
    vector<vector<bool>> st(H+1,vector<bool>(W+1,0));
    foe(i,1,H){
        foe(j,1,W){
            cin>>mp[i][j];
        }
    }
    string str;
    cin>>str;
    enum{
        U=0,
        R,
        D,
        L
    };
    int C=0;
    for(auto &it:str){
        int dY=Y,dX=X;
        switch(it){
        case 'U':
            dX+=dx[U];
            dY+=dy[U];
            break;
        case 'L':
            dX+=dx[L];
            dY+=dy[L];
            break;
        case 'R':
            dX+=dx[R];
            dY+=dy[R];
            break;
        case 'D':
            dX+=dx[D];
            dY+=dy[D];
            break;
        }
        if(mp[dX][dY]!='#'){
            Y=dY,X=dX;
            if(mp[dX][dY]=='@'&&st[dX][dY]==false){
                st[dX][dY]=true;
                C++;
            }
        }
    }
    cout<<X<<' '<<Y<<' '<<C<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}