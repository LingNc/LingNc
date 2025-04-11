#include<bits/stdc++.h>
using namespace std;
using i32=int;
using i64=long long;
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
using arr=vector<int>;
using PII=pair<int,int>;
#define endl '\n'
#define IOS std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int maxn=10000;

typedef class BigInt{
    int _data[maxn]={0};
    public:
    int len;
    BigInt():len(1){}
    template<typename T>
    BigInt(T num){
        init(num);
    }
    BigInt(const BigInt &other){
        operator=(other);
    }
    void init(i64 num){
        int k=0;
        while(num){
            _data[k++]=num%10;
            num/=10;
        }
        len=k;
    }
    void init(std::string num){
        len=num.size();
        for(int i=len;i>0;--i) _data[len-i]=num[i-1]-'0';
    }
    void flatten(int Len){
        len=Len;
        foe(i,0,len){
            _data[i+1]+=_data[i]/10;
            _data[i]%=10;
        }
        while(len>1&&!_data[len-1])
            len--;
        if(len==0) len=1;
    }
    void print(){
        fod(i,len-1,-1){
            cout<<_data[i];
        }
    }
    string str(){
        string res;
        fod(i,len-1,-1){
            res.push_back(_data[i]+'0');
        }
        return res;
    }
    int &operator[](int index){
        return _data[index];
    }
    int operator[](int index) const{
        return _data[index];
    }
    BigInt &operator=(const BigInt &a){
        len=a.len;
        foe(i,0,len){
            _data[i]=a._data[i];
        }
        return *this;
    }
}bigint;

BigInt operator+(const BigInt &a,const BigInt &b){
    BigInt res;
    int len=std::max(a.len,b.len);
    foe(i,0,len){
        res[i]=a[i]+b[i];
    }
    // 处理进位
    res.flatten(len+1);
    return res;
}
BigInt operator*(const BigInt &a,const BigInt &b){
    BigInt res;
    foe(i,0,a.len){
        foe(j,0,b.len){
            res[i+j]+=a[i]*b[j];
        }
    }
    // 处理进位
    res.flatten(a.len+b.len);
    return res;
}
// 高精度快速幂
BigInt pow(BigInt a,int b){
    bigint res=1,t=a;
    while(b){
        if(b&1) res=res*t;
        t=t*t;
        b>>=1;
    }
    return res;
}
void solve(){
    string d;
    int n;
    cin>>n>>d;
    if(d.substr(d.size()-2)==".0"){
        d.pop_back();
        d.pop_back();
    }
    string num;
    int point=d.size();
    foe(i,0,d.size()){
        if(d[i]!='.') num.push_back(d[i]);
        else{
            point=i+1;
        }
    }
    point=d.size()-point;
#define all(a) a.begin(),a.end()
    bigint res,big(num),mi;
    mi=pow(bigint(2),n);
    res=big*mi;
    string t=res.str();
    string ans;
    ans=t.substr(0,t.size()-point);
    if(t[t.size()-point]>='5'){
        bigint temp(ans);
        temp=temp+1;
        ans=temp.str();
    }
    cout<<ans<<endl;
}

int main(){
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}