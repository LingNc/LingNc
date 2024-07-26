#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
#define ll long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'

using namespace std;

const int N=1e3+10;
int n,m;
int A[N][N],B[N][N];
int X[N*N],Y[N*N],hh,tt;
void solve(){
    cin>>n>>m;
    int sum=0;
    foe(i,1,n)
        foe(j,1,m){
            cin>>A[i][j];
            if(A[i][j]==0) sum++; 
        }
    if(sum==n*m){
        cout<<0<<endl;
        return;
    }
    hh=0,tt=-1;
    foe(i,1,n-1){
        foe(j,1,m-1){
            if(A[i][j]==1&&A[i+1][j]==1&&A[i][j+1]==1&&A[i+1][j+1]==1){
                X[++tt]=i,Y[tt]=j;
                B[i][j]=1,B[i+1][j+1]=1,B[i+1][j]=1,B[i][j+1]=1;
            }
        }
    }
    bool res=1;
    foe(i,1,n)foe(j,1,m){
        if(A[i][j]!=B[i][j]){
            res=0;
            break;
        } 
    }
    int k=tt-hh;
    if(res)
        cout<<((k>=0)?k+1:k)<<endl;
    else{
        cout<<-1<<endl;
        return;
    }
    while(hh<=tt){
        cout<<X[hh]<<' '<<Y[hh++]<<endl;
    }
}
int main(){
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}