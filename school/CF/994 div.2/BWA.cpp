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

void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    char l=str[0];
    char r=str[n-1];
    bool res=true;
    int pl=0,pr=n-1;
    if(l=='.'||r=='.'){
        if(l=='.'&&r=='.'){
            foe(i,1,n-1){
                if(str[i]!='.'){
                    res=false;
                    break;
                }
            }
        }
        else{
            if(l=='.'){
                foe(i,0,n)
                    if(str[pl++]!='.')
                        break;
                pl--;
            }
            if(r=='.'){
                fod(i,n-1,0)
                    if(str[pr--]!='.')
                        break;
                pr++;
            }
            l=str[pl];r=str[pr];
        }
    }
    if(l=='s'&&r=='s'){
        foe(i,pl+1,pr){
            if(str[i]=='p'){
                res=false;
                break;
            }
        }
    }
    else if(l=='p'&&r=='p'){
        foe(i,pl+1,pr){
            if(str[i]=='s'){
                res=false;
                break;
            }
        }
    }
    else if(l=='p'&&r=='s')
        res=false;
    else{
        int s1=0,s2=0;
        foe(i,pl+1,pr){
            if(str[i]=='p') s1++;
            if(str[i]=='s') s2++;
        }
        if(str[0]=='.'&&s1!=0) res=false;
        if(str[n-1]=='.'&&s2!=0) res=false;
        if(s1!=0&&s2!=0) res=false;
    }
    yes(res);
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}