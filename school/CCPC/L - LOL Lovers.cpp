#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<tuple>
#include<set>
#define ll long long
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define endl '\n'

using namespace std;
pair<int,int> num(string str);
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int O1,O2,L1,L2;
    bool flag=0;
    foe(i,1,str.size()-1){
        tie(O1,L1)=num(str.substr(0,i));
        tie(O2,L2)=num(str.substr(i));
        if(O1!=O2&&L1!=L2){
            cout<<i<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0) cout<<-1<<endl;
    // int r=0,l=str.size()-1,m;
    // while(r+1<l){
    //     m=r+(l-r)>>1;
    //     if(check()){

    //     }
    // }
}
int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
pair<int,int> num(string str){
    pair<int,int> ol(0,0);
    foe(i,0,str.size()-1){
        if(str[i]=='O'){
            ol.first++;
        }
        else{
            ol.second++;
        }
    }
    return ol;
}
