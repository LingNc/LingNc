#include<bits/stdc++.h>
#define endl '\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

struct Team{
    char sign;
    int sec;
    Team(string time,char sign):sign(sign){
        sec=0;
        time.erase(2,1);
        time.erase(4,1);
        foe(i,0,2){
            sec=60*sec+stoi(time.substr(i*2,2));
        }
    }
    bool operator<(Team &b){
        return sec<b.sec;
    }
    bool operator>(Team &b){
        return sec>b.sec;
    }
};
bool compare(const Team &a, const Team &b) {
    return a.sec < b.sec;
}
unordered_map<string,vector<Team>> mp;
int main(){
    int t;
    cin>>t;
    string time,name;
    char sign;
    foe(i,1,t){
        cin>>name>>sign>>time;
        mp[name].push_back(Team(time,sign));
    }
    int n;
    cin>>n;
    foe(i,1,n){
        cin>>name>>time;
        Team tm(time,'0');
        auto &arr=mp[name];
        sort(arr.begin(),arr.end(),compare);
        string res="";
        for(auto &it:arr){
            if(it<tm) res+=it.sign;
        }
        if(res=="") cout<<0<<endl;
        else cout<<res<<endl;
    };
    return 0;
}