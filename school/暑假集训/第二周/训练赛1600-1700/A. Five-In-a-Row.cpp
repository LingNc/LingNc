#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define ll long long
using i64=long long;
using namespace std;
const int N=1e1+10;
char g[N][N];
int dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1};

bool win(int x,int y){
    int res[4]={1,1,1,1};
    foe(t,0,7){
        int a=x,b=y;
        foe(i,0,3){
            a+=dx[t],b+=dy[t];
            if(a<0||a>9||b<0||b>9) break;
            if(g[a][b]=='X') res[(t+4)%4]++;
            else break;
        }
    }
    foe(i,0,3){
        if(res[i]>=5) return true;
    }
    return false;
}
void solve(){
    foe(i,0,9)foe(j,0,9)
        cin>>g[i][j];
    foe(i,0,9)foe(j,0,9){
        if(g[i][j]!='X'&&g[i][j]!='O'){
            if(win(i,j)){
                cout<<"YES"<<endl;
                return ;
            }
        }
    }
    cout<<"NO"<<endl;
}
signed main(){
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}