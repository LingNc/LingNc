#include <bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for (int i=a; i<=b;i++)
#define endl '\n'

using namespace std;
string dtos(int num);
int main(){
    string f;
    cin>>f;
    //stack<int> stk;
    while(f.find('(')!=f.npos){
        auto it=f.begin();
        for(it;it<f.end();it++){
            if(*it=='2'&&*(it+1)=='('&&*(it+3)==')'){
                int num=*(it+2)-'0';
                f.replace(it-f.begin(),4,dtos((int)pow(2,num)));
            }
        }
        for(auto it=f.begin();it<f.end();it++){
            if(*it=='+'
            &&*(it-1)!='('&&*(it-1)!=')'
            &&*(it+1)!='('&&*(it+1)!=')'){
                int a=*(it-1)-'0',b=*(it+1)-'0';
                f.replace((it-1)-f.begin(),3,dtos(a+b));
            }
        }
    }
    cout<<f;
    return 0;
}
string dtos(int num){
    string res;
    if(num==0){
        res+='0';
        return res;
    }
    while(num){
        res+=num%10+'0';
        num/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}