#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

string add (char a, char b, char c)
{
    string s = "\0";
    s += a;
    s += b;
    s += c;
    return s;
}
char g[9][12];
vector<string> arr={"132","143","463","362","152","145","546","562"};
bool eq(string &str1,string &str2){
    string str3=str2+str2;
    foe(i,0,2){
        if(str3.substr(i,3)==str1) return true;
    }
    return false;
}
bool eq_num(string &str1,string &str2){
    vector<int> b(10,0);
    for(auto &i:str1) b[i-'0']++;
    for(auto &i:str2){
        if(b[i-'0']==0) return false;
    }
    return true;
}
bool have(string &str){
    for(auto &t:arr){
        if(eq(t,str)) return true;
    }
    return false;
}

bool num(string &str){
    for(auto &i:arr){
        if(eq_num(str,i)) return true;
    }
    return false;
}
void out_num(string &str){
    vector<int> b(10,0);
    for(auto &i:str){
        b[i-'0']++;
    }
    foe(i,0,9){
        if(b[i]==0) cout<<i;
    }
    cout<<endl;
}
void solve(){
    foe(i,0,8)foe(j,0,11){
        cin>>g[i][j];
    }
    vector<string> brr;
    string s = "\0";
    s += g[2][3];
    s += g[3][3];
    s += g[3][2];
    brr.push_back(s);
    brr.push_back(add(g[2][5],g[3][6],g[3][5]));
    brr.push_back(add(g[5][2],g[5][3],g[6][3]));
    brr.push_back(add(g[5][5],g[5][6],g[6][5]));
    brr.push_back(add(g[0][5],g[3][9],g[3][8]));
    brr.push_back(add(g[0][3],g[3][0],g[3][11]));
    brr.push_back(add(g[5][0],g[8][3],g[5][11]));
    brr.push_back(add(g[5][8],g[5][9],g[8][5]));
    for(auto &i:brr){
        if(!have(i)&&num(i)){
            out_num(i);
            return ;
        }
    }
    cout<<"No problem"<<endl;
}
i32 main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}