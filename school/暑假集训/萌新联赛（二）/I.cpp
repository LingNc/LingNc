#include<bits/stdc++.h>
#define int long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

signed main(){
    int n;
    string str;
    cin>>n>>str;
    string s="chuan";
    int sum=0;
    int ma=str.size()-5;
    for(int i=0;i<=ma;i++){
        if(str.substr(i,5)==s){
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}