#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
void solve();
int main(){
    ios::sync_with_stdio(0);
    //int T;cin>>T;while(T--)
        solve();
    
}
void solve(){
    int dead,cpy,p1,p2;
    cin>>dead>>cpy>>p1>>p2;
    bool flag=(p1<p2)?1:0;
    if(flag==false) swap(p1,p2);
    if(p1<dead&&p2>=cpy){
        cout<<((flag)?p1:p2)<<"-Y "<<((flag)?p2:p1)<<"-Y"<<endl;
        cout<<"qing "<<((flag)?2:1)<<" zhao gu hao "<<((flag)?1:2)<<endl;
    }
    else if(p1>=dead&&p2>=dead){
        cout<<((flag)?p1:p2)<<"-Y "<<((flag)?p2:p1)<<"-Y"<<endl;
        cout<<"huan ying ru guan"<<endl;
    }
    else if(p1<dead&&p2<dead){
        cout<<((flag)?p1:p2)<<"-N "<<((flag)?p2:p1)<<"-N"<<endl;
        cout<<"zhang da zai lai ba"<<endl;
    }
    else{
        cout<<((flag)?p1:p2)<<"-N "<<((flag)?p2:p1)<<"-Y"<<endl;
        cout<<((flag)?2:1)<<": huan ying ru guan"<<endl;
    }
}