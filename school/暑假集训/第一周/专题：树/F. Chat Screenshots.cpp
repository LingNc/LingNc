#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
#define INF 0x3f3f3f3f
//#define int long long
using i32=signed;
using i64=long long;
using namespace std;

const int N=1e6+10;
int e[2*N],ne[2*N],h[N],idx;
int temp[N],in[N];
int n,k;
void init(){
    foe(i,0,n){
        h[i]=-1;
        in[i]=0;
    }
    idx=0;
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    in[b]++;
}
bool topsort(){
    queue<int> q;
    foe(i,1,n)
        if(!in[i]) q.push(i);
    int cnt=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        cnt++;
        for(int p=h[t];p!=-1;p=ne[p]){
            int j=e[p];
            if(!(--in[j])) q.push(j);
        }
    }

    if(cnt==n) return true;
    else return false;
}

void solve(){
    cin>>n>>k;
    init();
    foe(i,1,k){
        foe(j,1,n) cin>>temp[j];
        foe(j,2,n-1) add(temp[j],temp[j+1]);
    }
    if(topsort()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

i32 main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}