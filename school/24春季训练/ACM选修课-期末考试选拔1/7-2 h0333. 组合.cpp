#include <bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
using namespace std;


void solve(int T){
    ios::sync_with_stdio(0),cin.tie(0);

    vector<string> mooc(T,"");
    vector<string> stu(5);
    map<string,int> M;
    foe(i,1,T){
        foe(j,0,4){
            cin>>stu[j];
        }
        sort(stu.begin(),stu.end());
        foe(j,0,4){
            mooc[i-1]+=stu[j];
        }
        M[mooc[i-1]]++;
    }
    int Ma=0,num=1;
    for(auto it=M.begin();it!=M.end();it++){
        if(it->second>Ma){
                Ma=it->second;
                num=1;
        }
        else if(it->second==Ma){
            num++;
        }
    }
    cout<<num*Ma<<endl;
}

int main(){
    int T=1;
    while(1){
        cin>>T;
        if(T==0) break;
        solve(T);
    }
    return 0;
}
