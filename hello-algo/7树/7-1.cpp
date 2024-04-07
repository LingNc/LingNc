#include<iostream>
#include<algorithm>
#include<string>
#define ll long long
#define endl '\n'
#include<stack>
#include<vector>
using namespace std;
bool str(string s);
int main(){
    string s;
    cin>>s;
    string end;
    cin>>end;
    string othr;
    cin>>othr;
    //cout<<str(s)<<endl;
    int size=0;
    vector<string> ss(100000,"");
    int k=0;
    while(1){
        auto it=s.begin()+1;
        for(it;it<s.end();it++){
            auto m=*it;
            *it=*(it-1);
            *(it-1)=m;
            int flag=0;
            for(int l=0;l<=k-1;l++){
                if(ss[l]==s){
                    flag=1;
                    break;
                }
                if(l==k-1) flag=0;
            }
            //if(flag==0) goto l2;
            if((k>=1&&ss[k-1]!=s)&&flag==0||k==0){
                ss[k]+=s;
                k++;
            }
            if(s==end&&k!=1) goto label;
            //cout<<s<<' ';
            continue;
        }
    }
label:
    int num=0;
    for(int i=0;i<=k-1;i++){
        if(str(ss[i])) num++;
    }
    int flag=0;
    for(int l=0;l<=k-1;l++){
        if(ss[l]==othr){
            flag=1;
            break;
        }
        if(l==k-1) flag=0;
    }
    if(flag==0) num++;
    cout<<num<<endl;
    return 0;
}
bool str(string s){
    stack<char> stk;
    auto it=s.begin();
    for(auto i=it;i<s.end();i++){
        if(*i=='('){
            stk.push('1');
        }
        else{
            if(stk.empty()==true) return false;
            stk.pop();
        }
    }
    if(stk.empty()==true)
        return true;
    else
        return false;
}
bool fin(vector<string> ss,string s){
    bool flag=0;
    for(int l=0;l<=ss.size()-1;l++){
        if(ss[l]==s){
            flag=1;
            break;
        }
        if(l==ss.size()-1) flag=0;
    }
    return flag;
}