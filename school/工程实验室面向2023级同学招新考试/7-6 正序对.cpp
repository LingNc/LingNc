#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define endl '\n'
using namespace std;

struct p{
    int i,j;
};
void solve(){
    int n;
    cin>>n;
    if(n>1){
        vector<int> num(n);
        foe(i,0,n-1){
            cin>>num[i];
        }

        vector<p> res;
        p temp;
        foe(i,0,n-2)foe(j,i+1,n-1){
            if(num[i]<num[j]){
                temp.i=num[i];
                temp.j=num[j];
                res.push_back(temp);
            }
        }
        cout<<res.size()<<endl;
        if(res.empty()==false){
            foe(i,0,res.size()-1){
                cout<<'('<<res[i].i<<','<<res[i].j<<')';
            }
        }
    }
    else{
        cout<<0<<endl;
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