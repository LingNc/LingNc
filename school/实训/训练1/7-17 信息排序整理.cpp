#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define string char
#define endl '\n'
using namespace std;

struct Virus{
    int id,infect,pathogen;

    bool operator<(const Virus &other) const{
        return (infect!=other.infect
            ?infect<other.infect
            :pathogen>other.pathogen);
    }
};
void solve(){
    int n;
    while(scanf("%d",&n)!=EOF){
        Virus vir[n];
        foe(i,1,n){
            auto &it=vir[i-1];
            cin>>it.id>>it.infect>>it.pathogen;
        }
        sort(vir,vir+n);
        cout<<"result:"<<endl;
        foe(i,0,n-1){
            auto &it=vir[i];
            cout<<it.id<<' '<<it.infect<<' '<<it.pathogen;cout<<endl;
        }
    }
}

int main(){
    int T=1;
    // cin>>T;
    solve();

    return 0;
}