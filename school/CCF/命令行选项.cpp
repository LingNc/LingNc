#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(b);i>=(b);i--)
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define all(a) a.begin(),a.end()
#define int long long
// #define endl '\n'
using namespace std;
using i32=signed;
using i64=long long;

typedef vector<int> arr;
typedef pair<int,int> PII;

bool rd(string &temp){
    cin>>temp;
    char ch=getchar();
    if(ch=='\n') return false;
    else return true;
}

void solve(){
    string com;
    cin>>com;
    string yes,no;
    foe(i,0,com.size()-1){
        if(i<=com.size()-2){
            if(com[i+1]==':'){
                yes.push_back(com[i]);
                i++;
            }
            else no.push_back(com[i]);
        }
        else{
            if(com[i]!=':') no.push_back(com[i]);
        }
    }

    int n;
    cin>>n;
    string str;
    foe(i,1,n){
        vector<string> res(1,"Case ");
        res[0].push_back('0'+i);res[0]+=':';

        int tim=0;
        bool end=true;
        while(end){
            if(!tim){
                end=rd(str);
                tim++;
                if(end==false) continue;
            }
            end=rd(str);
            if(str.size()==2&&str[0]=='-'&&str[1]!='-'){
                if(no.find(str[1])!=no.npos){
                    if(find(all(res),str)==res.end())
                        res.push_back(str);
                }
                else if(yes.find(str[1])!=yes.npos){
                    if(end==false) continue;
                    foe(i,1,res.size()-1){
                        if(res[i].substr(0,2)==str) res.erase(res.begin()+i);
                    }
                    string t=str+" ";
                    end=rd(str);
                    t+=str;
                    res.push_back(t);
                }
                else while(end) end=rd(str);
            }
            else while(end) end=rd(str);
        }
        sort(res.begin()+1,res.end(),less<string>());
        foe(i,0,res.size()-1){
            if(i!=0) cout<<" ";
            cout<<res[i];
        }
        cout<<endl;
    }
}
i32 main(){
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}