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
    int num=0;
    if(judge(str)==0){
        int right=0,left=0;
        int sum=0;
        int flag=0;
        for(auto it=str.end()-1;it>=str.begin();it--){
            if(*it==')') right++;
            if(*it=='('){
                left++;
                while(left){
                    if(flag==0){
                        if(right<=2){
                            sum+=0;
                            left-=1;
                        }
                        else if(right>=3){
                            if(right>=3){
                                left-=1;
                                right-=2;
                                sum+=2;
                                flag=1;
                            }
                        }
                    }
                    else{
                        left-=1;
                        right-=1;
                        sum+=1;
                    }
                    
                }
            }
        }
        cout<<sum<<endl;
    }
    else{
        cout<<0<<endl;
    }

}
bool judge(string& str){
    stack<int> stk;
    bool res=true;
    for(auto i:str){
        if(i=='('){
            stk.push(1);
        }
        else{
            if(stk.empty()==true){
                res=false;
                break;
            }
            stk.pop();
        }
    }
    int num=0;
    for(auto i:str) if(i=='(') num++;
    if(num>str.size()/2){
        int mid=(str.size()-1)/2;
        foe(i,0,mid){
            char t=str[i];
            str[i]=str[str.size()-1-i];
            str[str.size()-1-i]=t;
        }
        for(auto &i:str) i=(i=='(')?')':'(';
    }
    if(res)
        return (stk.empty())?true:false;
    else 
        return res;
}
int main( ){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
