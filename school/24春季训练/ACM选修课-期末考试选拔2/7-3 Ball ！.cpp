#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

void solve(){
    int N,Q,a,b,color;
    cin>>N>>Q;
    vector<set<int> > box(N+1);
    //vector<int> box(N+1,0);
    foe(i,1,N){
        cin>>color;
        box[i].insert(color);
    }

    foe(i,1,Q){
        cin>>a>>b;
        for(auto it=box[a].begin();it!=box[a].end();it++){
            box[b].insert(*it);
        }
        box[a].clear();
        cout<<box[b].size()<<endl;
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
