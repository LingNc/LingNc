#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b){return a/gcd(a,b)*b;}
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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
typedef vector<double> arr;
typedef pair<int,int> PII;

const i32 N=0;

double f(char opt,double a,double b){
    if(opt=='+') return a+b;
    else if(opt=='-') return a-b;
    else if(opt=='*') return a*b;
    else{
        if(b==0) return INF32;
        return a/b;
    }
}
bool eq24(arr &lis){
    string op="+-*/";
    double ans=0;
    for(auto &t1:op){
        for(auto &t2:op){
            for(auto &t3:op){
                double s1=f(t1,lis[0],lis[1]),s2=f(t2,lis[1],lis[2]),s3=f(t3,lis[2],lis[3]);
                if(s1==INF32||s2==INF32||s3==INF32) return false;

                ans=f(t2,s1,s3);
                double l;
                if(fabs(ans-24)<1e-5) return true;

                l=f(t2,s1,lis[2]);
                ans=f(t3,l,lis[3]);
                if(ans==INF32||l==INF32) return false;
                if(fabs(ans-24)<1e-5) return true;

                l=f(t2,lis[1],s3);
                ans=f(t1,lis[0],l);
                if(ans==INF32||l==INF32) return false;
                if(fabs(ans-24)<1e-5) return true;

                l=f(t1,lis[0],s2);
                ans=f(t3,l,lis[3]);
                if(ans==INF32||l==INF32) return false;
                if(fabs(ans-24)<1e-5) return true;

                l=f(t3,s2,lis[3]);
                ans=f(t1,lis[0],l);
                if(ans==INF32||l==INF32) return false;
                if(fabs(ans-24)<1e-5) return true;
            }
        }
    }
    return false;
}
arr path(4,0);
bool st[5];
void init(){
    memset(st,0,sizeof st);
    for(auto &i:path) i=0;
}
bool dfs(int u,arr &lis){
    bool ans=false;
    if(u==3){
        ans=eq24(path);
        for(auto &i:path) cout<<i<<' ';
        cout<<endl;
        return ans;
    }
    foe(i,0,3){
        if(!st[i]){
            st[i]=true;
            path[u+1]=lis[i];
            bool t=dfs(u+1,lis);
            ans=ans||t; 
            st[i]=false;
        }
    }
    return ans;
}


void solve(){
    init();
    arr a(4,0);
    string str;
    foe(i,0,3){
        cin>>str;
        if(str=="A") a[i]=1;
        else if(str=="J") a[i]=11;
        else if(str=="Q") a[i]=12;   
        else if(str=="K") a[i]=13;
        else a[i]=stod(str);
    }
    if(dfs(-1,a)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}