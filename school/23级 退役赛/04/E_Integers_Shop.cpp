#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
#define fod(i,a,b) for(int i=(a);i>(b);i--)
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

typedef struct Num{
    int length,price,start,end,id;
    bool operator<(struct Num &other){
        if(this->start==other.start)
            return this->price<other.price;
        else
            return this->start<other.start;
    }
    bool operator>(struct Num &other){
        if(this->end==other.end)
            return this->price<other.price;

        else
            return this->end>other.end;
    }
}Num;
void solve(){
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> price;
    int l,r,val;
    Num max_num,min_num;
    max_num.end=-1;
    min_num.start=1e9+10;
    foe(i,0,n){
        cin>>l>>r>>val;
        // price[i].first.first=l;
        // price[i].first.second=r;
        // price[i].second=val;
        Num temp;
        temp.start=l;
        temp.end=r;
        temp.length=r-l;
        temp.price=val;
        temp.id=i+1;
        if(temp<min_num) min_num=temp;
        if(temp>max_num) max_num=temp;

        int cost=0;
        int total_length=max_num.end-min_num.start;
        if(max_num.length==total_length||min_num.length==total_length){
            if(max_num.length==total_length&&min_num.length==total_length){
                cost=min(max_num.price,min_num.price);
            }
            else if(max_num.length==total_length){
                cost=max_num.price;
            }
            else if(min_num.length==total_length){
                cost=min_num.price;
            }
            cout<<cost<<endl;
        }
        else{
            cost=min_num.price+max_num.price;
            cout<<cost<<endl;
        }
    }
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}