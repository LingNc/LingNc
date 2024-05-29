#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define endl '\n'
using namespace std;
char last_num(string& str);
void solve(){
    int date;
    cin>>date;
    getchar();

    vector<string> list;
    string temp;
    char str[10]={0};
    char ch;
    while(scanf("%s%*c",str)!=EOF){
        list.push_back(str);
        memset(str,0,sizeof(str));
    }

    int sum=0;
    if(date<=5&&date>0){
        foe(i,0,list.size()-1){
            if(list[i].size()==6) continue;
            if(last_num(list[i])=='0'+date%5||last_num(list[i])=='0'+date%5+5){
                cout<<list[i]<<endl;
                sum++;
            }
        }
    }
    if(sum==0) puts("perfect");
}
char last_num(string& str){
    auto it=str.end()-1;
    for(it;it>=str.begin();it--){
        if(*it>='0'&&*it<='9'){
            return *it;
        }
    }
}
int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}