#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;


int a,b,c;
string num(9,'0');
bool st[11];
int res_num=0;
bool check(){
    int x=stod(num.substr(0,3)),y=stod(num.substr(3,3)),z=stod(num.substr(6,3));
    if(!(x%a)&&!(y%b)&&!(z%c)){
        if(x/a==y/b&&y/b==z/c){
            return true;
        }
    }
    return false;
}

void dfs(int u){
    if(u==9){
        if(check()){
            foe(i,0,8){
                if(!(i%3)) cout<<' ';
                cout<<num[i];
            }
            cout<<endl;
            res_num++;
        }
        return;
    }
    foe(i,1,9){
        if(st[i]) continue;
        st[i]=1;
        num[u]=i+'0';
        dfs(u+1);
        st[i]=0;
    }
}

void solve(){
    cin>>a>>b>>c;
    dfs(0);
    if(!res_num) cout<<"no!!!"<<endl;
}

i32 main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}