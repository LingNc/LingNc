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
int n;
map<arr,int> st;
string res;
int times;

bool check(arr &a,arr &b){
    for(int i=0,j=0;i<=n-1&&j<=n-1;i++,j++){
        if(a[i]!=b[j]) return false;
    }
    return true;
}

void dfs(arr &a,arr &ee){
    if(res.size()>n*n) return ;
    if(check(a,ee)){
        cout<<res<<endl;
        return ;
    }

    int t=a[0];
    a.erase(a.begin());
    a.push_back(t);
    
    if(st[a]!=1){
        st[a]=1;
        res.push_back('1');
        dfs(a,ee);
        res.pop_back();
    }
    
    a.insert(a.begin(),t);
    a.pop_back();

    t=a[1];
    a.erase(a.begin()+1);
    a.push_back(t);
    
    if(st[a]!=1){
        st[a]=1;
        res.push_back('2');
        dfs(a,ee);
        res.pop_back();
    }
    
    a.insert(a.begin()+1,t);
    a.pop_back();
}

void solve(){
    cin>>n;
    res.clear();
    st.clear();
    arr a(n,0),ee(n,0);
    foe(i,0,n-1) cin>>a[i];
    foe(i,0,n-1) cin>>ee[i];
    times=0;
    dfs(a,ee);
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}