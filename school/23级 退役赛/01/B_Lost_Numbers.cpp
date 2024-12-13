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
#define int long long
// #define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

int quest(int i,int j){
    cout<<"? "<<i<<' '<<j<<endl;
    int res;
    cin>>res;
    return res;
}

void solve(){
    arr a={ 4,8,15,16,23,42 };
    unordered_map<int,pair<int,int>> mp;
    foe(i,0,4)foe(j,i+1,5){
        mp[a[i]*a[j]]={ a[i],a[j] };
    }
    arr res(6,0);
    int num1=quest(1,2);
    int num2=quest(2,3);
    auto n1=mp[num1],n2=mp[num2];
    int i=0;
    if(n1.first==n2.first){
        res[i+1]=n1.first;
        res[i+0]=n1.second;
        res[i+2]=n2.second;
    }
    else if(n1.first==n2.second){
        res[i+1]=n1.first;
        res[i+0]=n1.second;
        res[i+2]=n2.first;
    }
    else if(n1.second==n2.first){
        res[i+1]=n1.second;
        res[i+0]=n1.first;
        res[i+2]=n2.second;
    }
    else if(n1.second==n2.second){
        res[i+1]=n1.second;
        res[i+0]=n1.first;
        res[i+2]=n2.first;
    }
    num1=quest(4,5);
    num2=quest(5,6);
    n1=mp[num1],n2=mp[num2];
    i=3;
    if(n1.first==n2.first){
        res[i+1]=n1.first;
        res[i+0]=n1.second;
        res[i+2]=n2.second;
    }
    else if(n1.first==n2.second){
        res[i+1]=n1.first;
        res[i+0]=n1.second;
        res[i+2]=n2.first;
    }
    else if(n1.second==n2.first){
        res[i+1]=n1.second;
        res[i+0]=n1.first;
        res[i+2]=n2.second;
    }
    else if(n1.second==n2.second){
        res[i+1]=n1.second;
        res[i+0]=n1.first;
        res[i+2]=n2.first;
    }
    cout<<"!";
    for(auto &it:res){
        cout<<' '<<it;
    }
    cout<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}