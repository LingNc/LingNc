#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>

#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a,b,j,c,d) foe(i,a,b)foe(j,c,d)
#define endl '\n'

using namespace std;

void solve(){
    stringstream ss;
    ss<<"5 6 8 6 9 1 6 1 2 4 9 1 9 8 2 3 6 4 7 7 5 9 5 0 3 8 7 5 8 1 5 8 6 1 8 3 0 3 7 9 2 7 0 5 8 8 5 7 0 9 9 1 9 4 4 6 8 6 3 3 8 5 1 6 3 4 6 7 0 7 8 2 7 6 8 9 5 6 5 6 1 4 0 1 0 0 9 4 8 0 9 1 2 8 5 0 2 5 3 3";
    string str;
    /*
    char ch=0;
    while(ss.rdbuf()->in_avail()!=0){
        ss>>ch;
        str.push_back(ch);
    }
    */
    str=ss.str();
    //string str1="5 6 8 6 9 1 6 1 2 4";
    //string s="1234";
    //remove(s.begin(),s.end(),'3');
    //cout<<s<<endl;
    //remove(str.begin(),str.end(),' ');
    str.erase(remove(str.begin(),str.end(),' '),str.end());
    //cout<<str1[10]<<*remove(str1.begin(),str1.end(),' ')<<' '<<str1<<endl;
    string year;
    foe(i,0,str.size()-1)foe(j,i+1,str.size()-1)foe(k,j+1,str.size()-1)foe(l,k+1,str.size()-1){
        year=str[i]+str[j]+str[k]+str[l];
        int y=stod(year);
        
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
bool ryear(int year){
    if(year%4==0&&year%100!=0||year%100==0&&year%400==0)
        return true;
    else
        return false;
}
