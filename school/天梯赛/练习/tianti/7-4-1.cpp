#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long


void print(vector<vector<int>> &res,int n){
    foe(i,1,n+1){
        foe(j,1,n+1){
            printf("%5lld",res[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void solve(){
    int n;
    scanf("%lld",&n);
    vector<vector<int>> res(n+1,vector<int>(n+1,0));
    int start=1,ins=0,ins_b=0;
    foe(i,1,n+1){
        start+=ins;
        if(i%2){
            foe(j,1,i+1){
                int x=j,y=i-j+1;
                res[x][y]=start-(j-1);
            }
        }
        else{
            foe(j,1,i+1){
                int x=j,y=i-(j-1);
                res[x][y]=start+(j-1);
            }
        }
        // print(res,n);
        if(i!=n){
            if(i%2) ins=1;
            else ins_b+=4,ins=ins_b;
        }
    }
    // print(res,n);
    start=n*n+1,ins=1,ins_b=-2;
    foe(i,1,n){
        start-=ins;
        if(i%2){
            foe(j,1,i+1){
                int x=n-(i-1)+j-1,y=n-(j-1);
                res[x][y]=start-(j-1);
            }
        }
        else{
            foe(j,1,i+1){
                int x=n-(i-1)+j-1,y=n-(j-1);
                res[x][y]=start+(j-1);
            }
        }
        // print(res,n);
        if(i%2) ins_b+=4,ins=ins_b;
        else ins=1;
    }
    print(res,n);
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}