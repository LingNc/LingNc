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


typedef struct Opt{
    string opt;
    vector<struct Opt> *oq;
    int x,y,r;
    int x1,y1,x2,y2;
    char col;
    bool is_render(int u,int v){
        if(opt=="Circle"){
            if((u-x)*(u-x)+(v-y)*(v-y)<=r*r){
                return true;
            }
        }
        if(opt=="Rectangle"){
            if(u>=x1&&u<=x2&&v>=y1&&v<=y2){
                return true;
            }
        }
        return false;
    }
    void one_render(int u,int v){
        auto q=*oq;
        for(auto i=q.rbegin();i!=q.rend();i++){
            auto it=*i;
            if(it.is_render(u,v)){
                cout<<it.col;
                return ;
            }
        }
        cout<<'.';
    }
    void render(){
        fod(i,y2,y1){
            foe(j,x1,x2){
                one_render(j,i);
            }
            cout<<endl;
        }
    }
}Opt;

void solve(){
    vector<Opt> q;
    string temp;
    int n;
    cin>>n;
    foe(i,1,n){
        cin>>temp;
        Opt t;
        t.opt=temp;
        if(temp=="Circle"){
            cin>>t.x>>t.y>>t.r>>t.col;
            q.push_back(t);
        }
        if(temp=="Rectangle"){
            cin>>t.x1>>t.y1>>t.x2>>t.y2>>t.col;
            q.push_back(t);
        }
        if(temp=="Render"){
            cin>>t.x1>>t.y1>>t.x2>>t.y2;
            t.oq=&q;
            t.render();
        }
    }
}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}