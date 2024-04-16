#include<iostream>
#include<algorithm>
#include<string>

#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
string DtoN(int m,int N);
int solve(){
    int num;
    cin>>num;
    cout<<DtoN(num,26)<<endl;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

string DtoN(int m,int N){
    string str;
    int num=m;
    while(num!=1){
        str.push_back(num%26+'A');
        num/=26;
    }
    return str;
}