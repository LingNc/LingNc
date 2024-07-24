#include<bits/stdc++.h>
#define ll long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;
//行列式
int cal(vector<vector<int>> &det,int n);

bool eql(string now,string res){
    for(int i=res.size()-1;i>=0;i--){
        if(now==res.substr(i,res.size())){
            return true;
        }
    }
    return false;
}

bool cmp(string a, string b){
	return a.length() < b.length();
}
void solve(){
    int n;
    cin>>n;
    map<string,vector<string>> lis;
    int num;
    string x;
    string name;
    foe(i,1,n){
        cin>>name>>num;
        foe(i,1,num){
            cin>>x;
            lis[name].push_back(x);
        }
    }
    cout<<lis.size()<<endl;
    for(auto it=lis.begin();it!=lis.end();it++){
        auto t=*it;
        auto name=t.first;
        auto q=t.second;
        sort(q.begin(),q.end(),cmp);
        foe(i,0,q.size()-1){
            foe(j,i+1,q.size()-1){
                if(eql(q[i],q[j])){
                    q.erase(q.begin()+i);
                    i--;
                    break;
                }
            }
        }
        sort(q.begin(),q.end());
        cout<<name<<' '<<q.size()<<' ';
        foe(i,1,q.size()){
            cout<<q[i-1]<<' ';
        }
        cout<<endl;
    }

}

signed main(){
    IOS;
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}