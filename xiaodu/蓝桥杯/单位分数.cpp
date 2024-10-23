#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
template<typename iii> iii gcd(iii a,iii b){ return (b==0)?a:gcd(b,a%b); }
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;


typedef struct fraction{
    int up,down;

    void insert(int _up,int _down){
        int _gcd=gcd(_up,_down);
        up=_up/_gcd;
        down=_down/_gcd;
        if(down<0) up*=-1,down*=-1;
    }

    fraction operator+(const fraction &b){
        return fraction(up*b.down+b.up*down,down*b.down);
    }
    fraction operator-(const fraction &b){
        return fraction(up*b.down-b.up*down,down*b.down);
    }
    bool operator==(const fraction &b){
        if(up==b.up&&down==b.down) return true;
        else return false;
    }
    bool check(){
        return (down-up)==1;
    }
    
    fraction(){
        up=1,down=1;
    }
    fraction(int _up,int _down){
        insert(_up,_down);
    }
}Fraction;

ostream &operator<<(ostream &o,const Fraction &b){
    o<<b.up<<'/'<<b.down;
    return o;
}

bool is_prime(int x){
    if(x<=3) return (x==1)?false:true;
    int sq=(int)sqrt(x);
    foe(i,2,sq) if(!(x%i)) return false;
    return true;
}

vector<Fraction> res(13);
bool st[35];
int n;

void dfs(int u,int last,Fraction &sum){
    if(u==n+1){
        foe(i,1,n) cout<<res[i]<<' ';
        return ;
    }
    if(u==n){
        if(sum.down<=30){
            res[u]=Fraction(1,sum.down);
            dfs(u+1,0,sum);
        }
        else{
            return ;
        }
    }
    foe(i,last+1,30){
        Fraction t(1,i);
        if((sum+t).check()){
            sum=sum+t;
            res[u]=t;
            dfs(u+1,i,sum);
        }
    }

}

void solve(){
    cin>>n;
    Fraction sum(0,1);
    dfs(1,1,sum);
}

i32 main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}