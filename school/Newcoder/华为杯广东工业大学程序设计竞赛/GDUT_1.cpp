#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
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
// 不包含+
arr to_num(string str){
    arr res(4,0);
    int k=1;
    fod(i,str.size()-1,0){
        char it=str[i];
        if(it=='G'){
            res[0]+=k;
        }
        else if(it=='D'){
            res[1]+=k;
        }
        else if(it=='U'){
            res[2]+=k;
        }
        else if(it=='T'){
            res[3]+=k;
        }
        if(k<(int)1e18)
            k*=10;
        // else
        //     k=0;
    }
    return res;
}
// 去掉+
vector<string> to_single(string &str){
    vector<string> res;
    string temp;
    for(auto it:str){
        if(it=='+'){
            res.push_back(temp);
            temp.clear();
        }
        else{
            temp+=it;
        }
    }
    res.push_back(temp);
    return res;
}
// 数组相加
arr to_add(arr &a,arr &b){
    arr res(4,0);
    foe(i,0,4){
        res[i]=a[i]+b[i];
    }
    return res;
}

void solve(){
    string str;
    int res;
    cin>>str>>res;
    vector<string> str_list=to_single(str);
    vector<arr> num_list;
    for(auto it:str_list){
        num_list.push_back(to_num(it));
    }
    arr sum(4,0);
    for(auto it:num_list){
        sum=to_add(sum,it);
    }
    foe(G,0,10){
        foe(D,0,10){
            foe(U,0,10){
                foe(T,0,10){
                    int ans=G*sum[0]+D*sum[1]+U*sum[2]+T*sum[3];
                    if(ans==res){
                        cout<<"YES"<<endl;
                        cout<<G<<' '<<D<<' '<<U<<' '<<T<<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<"NO"<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}