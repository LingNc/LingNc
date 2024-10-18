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
    int up,down,sign;

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

void dfs(int u){
    if(u==0){

    }
}

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;


    Fraction t1(a,b),t2(c,d);
    cout<<t1<<' '<<t2<<endl;
    auto e=t1+t2,f=t1-t2;
    cout<<t1+t2<<endl;
    cout<<t1-t2<<endl;
    cout<<f-e<<endl;
}

i32 main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}