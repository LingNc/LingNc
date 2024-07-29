#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define long long
using i64=long long;
using namespace std;

const int N=1e6+10;
int node[N];
signed main(){
    int n;
    cin>>n;
    int a,b;
    foe(i,1,n-1){
        cin>>a>>b;
        node[a]++,node[b]++;
    }
    int max_num=0,max_k=0,maxn=-1;
    vector<int> res;
    foe(i,1,n){
        if(node[i]>2){
            max_num++;
            max_k=i;
            maxn=(maxn,node[i]);
        }
        if(node[i]==1) res.push_back(i);
    }
    if(maxn<=2){
        cout<<"Yes"<<endl;
        cout<<1<<endl;
        for(auto &i:res){
            cout<<i<<' ';
        }
        return 0;
    }
    if(max_num>1){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    cout<<res.size()<<endl;
    for(auto &i:res){
        cout<<max_k<<' '<<i<<endl;
    }
    return 0;
}