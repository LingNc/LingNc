#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
#define endl '\n'
using i32=int;
using i64=long long;
using namespace std;
#define int long long
typedef vector<int> arr;
using PII=pair<int,int>;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(a) a.begin(),a.end();

void print(vector<vector<int>> &mp){
    foe(i,0,mp.size()){
        foe(j,0,mp[i].size()){
            cout<<mp[i][j]<<' ';
        }
        cout<<endl;
    }
}
int high=0;
int hang(vector<vector<int>> &mp,int x,int y){
    int sum=0;
    foe(i,y+1,mp[x].size()){
        if(mp[x][i]>=high) break;
        if(mp[x][i]<0) sum++;
    }
    fod(i,y-1,-1){
        if(mp[x][i]>=high) break;
        if(mp[x][i]<0) sum++;
    }
    return sum;
}

int lie(vector<vector<int>> &mp,int x,int y){
    int sum=0;
    foe(i,x+1,mp.size()){
        if(mp[i][y]>=high) break;
        if(mp[i][y]<0) sum++;
    }
    fod(i,x-1,-1){
        if(mp[i][y]>=high) break;
        if(mp[i][y]<0) sum++;
    }
    return sum;
}
void solve(){
    int n,m,h;
    cin>>n>>m>>h;
    high=h;
    vector<vector<int>> mp(n,vector<int>(m,0));
    int temp;
    foe(i,0,n){
        foe(j,0,m){
            cin>>mp[i][j];
        }
    }
    // print(mp);
    int res=0;
    int max_res=-1,max_x=-1,max_y=-1;
    foe(i,0,mp.size()){
        foe(j,0,mp[i].size()){
            if(mp[i][j]!=0) continue;
            int num=0;
            num+=hang(mp,i,j);
            num+=lie(mp,i,j);
            if(num>=3) res++; 
            if(num>max_res){
                max_res=num;
                max_x=i;
                max_y=j;
            }
        }
    }
    cout<<res<<endl;
    cout<<max_x<<' '<<max_y<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
