#include <bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
using namespace std;

void pri(vector<vector<int> > & M);

vector<int> have;

int fi(int node,int last,int total){
    if(find(have.begin(),have.end())!=have.npos)
    if()
}

void solve(){
    ios::sync_with_stdio(0),cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int> > frd(n,vector<int>(n,0));

    int i,j;

    foe(k,1,m){
        cin>>i>>j;
        frd[i][j]=1;
        frd[j][i]=1;
    }

    pri(frd);

    queue<int> q;
    int num=0;
    foe(i,0,n-1){
        have.clear();
        have.push_back(i);
        int m=fi(i);
    }
}

void pri(vector<vector<int> > & M){
    int n=M.size()-1;
    foe(i,0,n){
        foe(j,0,n){
            cout<<M[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        //if(T==0) break;
        solve();
    }
    return 0;
}
