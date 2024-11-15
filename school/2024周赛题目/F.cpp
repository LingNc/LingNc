#include<iostream>
#define endl '\n'
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    if(n%(m+1)==0)
        cout<<"ZCY"<<endl;
    else
        cout<<"WY"<<endl;
        return 0;
}
