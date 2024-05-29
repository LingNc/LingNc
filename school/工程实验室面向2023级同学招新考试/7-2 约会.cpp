#include<iostream>
#include<algorithm>
#define ll long long
#define endl '\n'
using namespace std;


int main(){
    int m1,m2;
    cin>>m1>>m2;
    getchar();
    string a,b;
    cin>>a>>b;

    int t1=stod(a.substr(0,2))*60+stod(a.substr(3,2));
    int t2=stod(b.substr(0,2))*60+stod(b.substr(3,2));
    if(t1<t2){
        if(t2-t1<=m1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else{
        if(t1-t2<=m2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}