#include<bits/stdc++.h>
#define foe(j,a,b) for(int j=(a);j<=(b);j++)
#define endl '\n'
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;
using i64=long long;
using i32=signed;

bool pre_cmp(string &src,string &pre){
    if(pre.size()>src.size()) return 0;
    else{
        foe(j,0,pre.size()-1){
            if(src[j]!=pre[j])
                return false;
        }
    }
    return true;
}

void solve(){
    int R,Q;
    cin>>R>>Q;
    string rule;
    unordered_map<string,vector<string>> mp;
    foe(j,1,R){
        cin>>rule;
        string preText;
        if(rule=="context")
            cin>>preText;
        else
            preText=".";
        int n;
        cin>>n;
        auto &it=mp[preText];
        string str;
        foe(j,1,n){
            cin>>str;
            it.push_back(str);
        }
    }
    string pre,word;
    foe(i,1,Q){
        vector<string> res;
        cin>>pre>>word;
        if(!mp.count(pre)) pre=".";
        auto &its=mp[pre];
        for(auto &it:its){
            if(pre_cmp(it,word))
                res.push_back(it);
        }
        if(res.size()==1&&res[0]==word||!res.size()){
            cout<<"EMPTY";
            if(i!=Q) cout<<endl;
            continue;
        }
        sort(all(res));
        auto last=unique(all(res));
        bool first=true;
        for(auto j=res.begin();j!=last;j++){
            auto &it=*j;
            if(first) cout<<it,first=false;
            else cout<<' '<<it;
        }
        if(i!=Q)cout<<endl;
    }
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}