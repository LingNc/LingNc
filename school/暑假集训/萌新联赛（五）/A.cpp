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

const i32 N=0;
// typedef struct Adj{
//     //边
//     struct edge{
//         int ds,ms,next;
//         edge(int ds,int ms,int next):ds(ds),ms(ms),next(next){}
//     };
//     //邻接表
//     vector<vector<edge>> mp;
//     //有没有走过
//     vector<char> st;
//     //指定最大节点数量
//     Adj(i64 N):mp(N,vector<edge>()),st(N,0){}
//     //初始化的节点个数
//     void init(int n){
//         foe(i,0,n){
//             mp[i].clear();
//             st[i]=false;
//         }
//     }
//     void add(int fa,int idx,int ds,int ms){
//         mp[fa].push_back(edge(ds,ms,idx));
//     }
// }adj;
bool leap(int year){
    if(year%4==0&&year%100!=0||year%100==0&&year%400==0)
        return true;
    else
        return false;
}
typedef struct {
    int y,m,d;
    int M[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
    int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool days(){
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
    bool mons(){
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
}tim;

// int days(tim t){
//     int res=214;
//     res+=t.M[t.m-1]+t.d;
//     res+=(leap(t.y))?1:0;
//     foe(i,t.y+1,2023){
//         if(leap(t.y)) res++;
//         res+=365;
//     }
//     return res;
// }
// int months(tim t){
//     int res=0;
//     res+=12-t.m;
//     res+=12*(2023-t.y);
//     res+=8;
//     if(t.d>1) res--;
//     res+=32-t.d;
//     return res;
// }
bool sg(int u,tim t){
    tim a=t,b=t;
    bool res_l=a.days(),res_r=b.mons();
    if(!res_l&&!res_r) return false;
    bool l,r;
    if(res_l&&res_r){
        l=sg(u+1,a);
        r=sg(u+2,b);
        if(l&&r) return false;
        else return true;
    }
    else if(res_l){
        l=sg(u+1,a);
        if(l) return false;
        else return true;
    }
    else if(res_r){
        r=sg(u+1,b);
        if(r) return false;
        else return true;
    }
}
void solve(){
    tim t;
    cin>>t.y>>t.m>>t.d;
    if(sg(1,t)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}