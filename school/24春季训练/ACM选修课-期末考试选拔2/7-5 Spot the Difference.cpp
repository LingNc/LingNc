#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

void solve(){
    int N;
    cin>>N;
    getchar();
    vector<vector<char> > A(N+1,vector<char>(N+1,0));
    foe(i,1,N)foe(j,1,N){
        cin>>A[i][j];
    }
    vector<vector<char> > B(N+1,vector<char>(N+1,0));
    foe(i,1,N)foe(j,1,N){
        cin>>B[i][j];
    }
    foe(i,1,N)foe(j,1,N){
        if(A[i][j]!=B[i][j]){
            cout<<i<<' '<<j<<endl;
            break;
        }
    }
}
int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
