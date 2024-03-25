#include<bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
string x(string &num,int n);
void solve(int n);
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}
void solve(int n){
    string result="1";
    foe(i,1,8*n-1){
        x(result,2);
    }
    auto i=result.end()-1;
    while(i!=result.begin()){
        if(*i=='0'){
            (*i)='9';
        }
        else{
            (*i)--;
            break;
        }
        i--;
    }
    cout<<result<<endl;
}
string x(string &num,int n){
    string s=num;
    num="0";
    int l,k,o;
    for(auto i=s.end()-1;i>=s.begin();i--){
        l=((*i-'0')*n);
        k=l/10,o=l%10;
        *num.begin()+=o;
        if(i==s.begin()&&k!=0||i!=s.begin()) num.insert(num.begin(),k+'0');
    }
    return num;
}