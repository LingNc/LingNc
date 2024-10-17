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
vector<vector<int>> mp(6,vector<int>(6,0)),st(6,vector<int>(6,0));
vector<vector<char>> res(6,vector<char>(6,0));
int n,num=0;

bool row(int x,int y,char ch){
    foe(i,0,5){
        if(i!=x&&res[i][y]==ch) return false;
    }
    return true;
}
bool col(int x,int y,char ch){
    foe(i,0,5){
        if(i!=y&&res[x][i]==ch) return false;
    }
    return true;
}
bool yizu(int x,int y,char ch){
    if(st[mp[x][y]][ch-'A']) return false;
    else return true;
}

void write(int x,int y,char ch){
    res[x][y]=ch;
    st[mp[x][y]][ch-'A']=1;
}
void erase(int x,int y,char ch){
    res[x][y]=0;
    st[mp[x][y]][ch-'A']=0;
}
void print(){
    for(auto &i:res){
        for(auto &j:i){
            cout<<j<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
void dfs(int x,int y,int other){
    if(other==0){
        num++;
        cout<<num<<endl;
        print();
        return;
    }

    x++;
    if(x>5) x%=6,y++;

    char ch='A';
    if(res[x][y]!=0){
        dfs(x,y,other-1);
        return;
    }
    foe(i,0,5){
        if(row(x,y,ch+i)&&col(x,y,ch+i)&&yizu(x,y,ch+i)){
            write(x,y,ch+i);
            dfs(x,y,other-1);
            erase(x,y,ch+i);
        }
    }
}


void solve(){
    char ch;
    foe(i,0,5)foe(j,0,5){
        cin>>ch;
        mp[i][j]=ch-'0';
    }
    cin>>n;
    string temp;
    foe(i,1,n){
        cin>>temp;
        int x=temp[0]-'0';
        int y=temp[1]-'0';
        char ch=temp[2];
        res[x][y]=ch;
        st[mp[x][y]][ch-'A']=1;
    }
    foe(i,0,5){
        if(row(0,0,'A'+i)&&col(0,0,'A'+i)&&yizu(0,0,'A'+i)){
            res[0][0]='A'+i;
            dfs(0,0,36-1);
            res[0][0]=0;
        }
    }

}
i32 main(){
    IOS;
    i32 T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}