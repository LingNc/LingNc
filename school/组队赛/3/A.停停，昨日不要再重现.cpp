#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
// #define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=1e3+10;
int mp[N][N];

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    string str;
    cin>>str;
    int u=1,d=n,l=1,r=m;
    int mu=1,md=n,ml=1,mr=m;
    fod(i,str.size()-1,0){
        auto it=str[i];
        if(it=='U') u--,d--;
        else if(it=='D') u++,d++;
        else if(it=='L') l--,r--;
        else if(it=='R') l++,r++;
        mu=max(mu,u);
        md=min(md,d);
        ml=max(ml,l);
        mr=min(mr,r);
    }
    if(md<mu||mr<ml){
        if(k==0) cout<<n*m<<endl;
        else{
            cout<<0<<endl;
        }
        return;
    }
    int nums=(mr-ml+1)*(md-mu+1);
    // cout<<nums;

    foe(i,0,2*n+10)foe(j,0,2*m+10) mp[i][j]=0;
    int zero_x=n+1,zero_y=m+1;
    int x=zero_x,y=zero_y;
    fod(i,str.size()-1,0){
        auto it=str[i];
        switch(it){
            case 'U':
                x--;
                break;
            case 'D':
                x++;
                break;
            case 'L':
                y--;
                break;
            case 'R':
                y++;
                break;
        }
        if(x<0) x=0;
        if(y<0) y=0;
        mp[x][y]=1;
    }

    foe(i,1,2*n+10)foe(j,1,2*m+10){
        mp[i][j]+=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
    }

    int res=0;
    int ix=mr-ml,iy=mr-ml;
    foe(i,zero_x-(mr-ml),zero_x+n-(mr-ml)){
        foe(j,zero_y-(md-mu),zero_y+m-(md-mu)){
            int num_k=mp[i][j]-mp[i-ix-1][j]-mp[i][j-iy-1]+mp[i-ix-1][j-iy-1];
            if(num_k==k) res++;
        }
    }
    cout<<res<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}