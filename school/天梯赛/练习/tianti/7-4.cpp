#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long


void solve(){
    int n;
    scanf("%lld",&n);
    vector<vector<int>> res(n+1,vector<int>(n+1,0));
    foe(i,0,n+1){
        res[0][i]=-1;
    }
    foe(i,0,n+1){
        res[i][0]=-1;
    }
    foe(i,1,n+1){
        int start=0;
        if(i%2){
            start=(i+1)*i/2;
            foe(j,0,i){
                int x=i-j,y=j+1;
                res[y][x]=start-j;
            }
        }
        else{
            start=(i-1)*i/2+1;
            foe(j,0,i){
                int x=i-j,y=j+1;
                res[y][x]=start+j;
            }
        }
    }
    int ss=(n+1)*n/2;
    foe(i,1,n){
        int start=0;
        if(i%2){
            start=ss+(n-1+1)*(n-1)/2-(n-1-i+1)*(n-1-i)/2;
            foe(j,0,n-i){
                int x=i-j,y=j+1;
                res[y][x]=start-j;
            }
        }
        else{
            start=ss+(n-1-1)*(n-1)/2-(n-1-i-1)*(n-1-i)/2+1;
            foe(j,0,n-i){
                int x=i-j,y=j+1;
                res[y][x]=start+j;
            }
        }
    }
    // 1 3 6 (1+n)n/2
    foe(i,1,n+1){
        foe(j,1,n+1){
            printf("%5d",res[i][j]);
        }
        putchar('\n');
    }
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}