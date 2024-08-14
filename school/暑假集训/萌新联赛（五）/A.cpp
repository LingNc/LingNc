#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
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

const i32 N=0;
int mon[13]={ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool leap(int year){
    if(year%4==0&&year%100!=0||year%100==0&&year%400==0)
        return true;
    else
        return false;
}
bool days(int &y,int &m,int &d){
    if(y==2024&&m==8&&d==1){
        return 0;
    }
    d++;
    mon[2]=(leap(y))?29:28;
    if(d>mon[m]){
        d=1;
        m+=1;
        if(m>12){
            m=1;
            y+=1;
        }
    }
    return 1;
}
bool mons(int &y,int &m,int &d){
    if(y==2024&&m==7&&d>1||y==2024&&m==8&&d==1){
        return 0;
    }
    m++;
    if(m>12){
        m=1;
        y++;
    }
    return 1;
}
map<vector<int>,bool> mp;
bool sg(vector<int> t){
    vector<int> a=t,b=t;
    bool l=days(a[0],a[1],a[2]),r=mons(b[0],b[1],b[2]);
    if(!mp.count(a)&&l) mp[a]=sg(a);
    if(!mp.count(b)&&r) mp[b]=sg(b);
    if(l&&r) return (mp[a]&&mp[b])?0:1;
    else if(l) return (mp[a])?0:1;
    else if(r) return (mp[b])?0:1;
    else return 0;
}
void solve(){
    vector<int> t(3,0);
    cin>>t[0]>>t[1]>>t[2];
    if(sg(t)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}