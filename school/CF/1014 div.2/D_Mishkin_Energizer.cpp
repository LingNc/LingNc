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

void solve(){
    int n;
    string s;
    cin>>n>>s;

    int cnt_L=0,cnt_I=0,cnt_T=0;
    for(char c:s){
        if(c=='L') cnt_L++;
        else if(c=='I') cnt_I++;
        else if(c=='T') cnt_T++;
    }

    if(cnt_L==cnt_I&&cnt_I==cnt_T&&n%3==0){
        cout<<0<<endl;
        return;
    }

    bool has_diff=false;
    foe(i,0,n-1){
        if(s[i]!=s[i+1]){
            has_diff=true;
            break;
        }
    }

    if(!has_diff){
        cout<<-1<<endl;
        return;
    }

    int max_count=max({ cnt_L,cnt_I,cnt_T });
    int ceil_n3=(n+2)/3;
    int k_start=max(max_count,ceil_n3);
    int k_end=n;
    bool found=false;
    arr ops;

    for(int k=k_start;k<=k_end;k++){
        int m=3*k-n;
        if(m<0||m>2*n) continue;
        int a=k-cnt_L;
        int b=k-cnt_I;
        int c=k-cnt_T;
        if(a<0||b<0||c<0) continue;

        string curr=s;
        int ra=a,rb=b,rc=c;
        ops.clear();
        bool ok=true;

        while(ra>0||rb>0||rc>0){
            bool inserted=false;
            foe(i,0,(int)curr.size()-1){
                if(curr[i]==curr[i+1]) continue;
                char x=curr[i],y=curr[i+1];
                char z;
                if((x=='L'&&y=='I')||(x=='I'&&y=='L')) z='T';
                else if((x=='L'&&y=='T')||(x=='T'&&y=='L')) z='I';
                else if((x=='I'&&y=='T')||(x=='T'&&y=='I')) z='L';
                else continue;

                if(z=='L'&&ra>0){
                    curr.insert(i+1,1,'L');
                    ops.push_back(i+1);
                    ra--;
                    inserted=true;
                    break;
                }
                else if(z=='I'&&rb>0){
                    curr.insert(i+1,1,'I');
                    ops.push_back(i+1);
                    rb--;
                    inserted=true;
                    break;
                }
                else if(z=='T'&&rc>0){
                    curr.insert(i+1,1,'T');
                    ops.push_back(i+1);
                    rc--;
                    inserted=true;
                    break;
                }
            }
            if(!inserted){
                ok=false;
                break;
            }
        }

        if(ok){
            found=true;
            break;
        }
    }

    if(found){
        cout<<ops.size()<<endl;
        for(int op:ops){
            cout<<op<<endl;
        }
    }
    else{
        cout<<-1<<endl;
    }
}

i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}