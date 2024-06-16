#include<bits/stdc++.h> 
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

bool judge(string& str);

void solve(){
    string str;
    cin>>str;
    string res;
    int sum=0;
    if(judge(str)==0){
        for(auto &i:str){
            i=(i=='(')?')':'(';
            bool r=judge(str);
            if(r==1)
                sum++;
            res.push_back('0'+r);
            i=(i=='(')?')':'(';
        }
        cout<<sum<<endl<<res<<endl;
    }
    else{
        cout<<0<<endl;
    }

}
bool judge(string& str){
    stack<int> stk;
    for(auto i:str){
        if(i=='(') stk.push(1);
        else{
            if(stk.empty()==true)
                return false;
            stk.pop();
        }
    }
    return (stk.empty())?true:false;
}
int main( ){
    //ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
