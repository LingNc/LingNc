#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
#define all(a) a.begin(),a.end()


bool is_num(string str){
    if(str.size()%2){
        if(str[str.size()/2]!='1'&&
        str[str.size()/2]!='0'&&
        str[str.size()/2]!='8')
        return false;
        if(!(str[str.size()/2]=='1'||
        str[str.size()/2]=='0'||
        str[str.size()/2]=='8')){
            return false;
        }
    }
    foe(i,0,str.size()/2){
        if(str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='7'){
            return false;
        }
        if(str[i]=='6'&&str[str.size()-i-1]!='9'){
            return false;
        }
        if(str[i]=='9'&&str[str.size()-i-1]!='6'){
            return false;
        }
        if(str[i]=='1'&&str[str.size()-i-1]!='1'){
            return false;
        }
        if(str[i]=='0'&&str[str.size()-i-1]!='0'){
            return false;
        }
        if(str[i]=='8'&&str[str.size()-i-1]!='8'){
            return false;
        }
    }
    return true;
}

void solve(){
    int F,n;
    cin>>F>>n;
    int ans=0;
    foe(i,1,F+1){
        foe(j,1,n+1){
            string strF=to_string(i);
            string strn;
            if(j<10){
                strn+='0';
                strn+=to_string(j);
            }
            else{
                strn=to_string(j);
            }
            string str=strF+strn;
            if(is_num(str)){
            // cout<<str<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;

}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}