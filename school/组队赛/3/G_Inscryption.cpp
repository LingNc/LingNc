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
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=0;

void solve(){
    int n;
    cin>>n;
    int opt,num=1,atck=1;
    arr a(n+1,0),b(n+1,0);
    int sum=1,flag=1;
    foe(i,1,n){
        cin>>a[i];
        if(a[i]==0) sum+=1;
        else sum+=a[i];
        if(sum<1){
            flag=0;
        }
    }
    if(flag==0){
        cout<<-1<<endl;
        return;
    }
    fod(i,n,1){
        int t=a[i];
        if(a[i]==0) t=-1;
        if(i==n){
            b[i]=t;
            continue;
        }
        b[i]=t+((a[i+1]==0)?-1:a[i]);
    }
    int add=0;
    foe(i,1,n){
        opt=a[i];
        if(opt==1){
            num++;
            atck++;
        }
        else if(opt==0){
            if(b[i]+1<=0){
                num++;
                atck++;
            }
            else
                num--;
        }
        else if(opt==-1){
            num--;
        }
    }
    int _gcd=gcd(num,atck);
    cout<<atck/_gcd<<' '<<num/_gcd<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}