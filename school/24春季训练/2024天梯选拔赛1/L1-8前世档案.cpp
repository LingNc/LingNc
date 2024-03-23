#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;

int result(string &Q);
int main(){
    int N,M;
    cin>>N>>M;
    foe(i,1,M){
        string Q;
        cin>>Q;
        getchar();
        cout<<result(Q)<<endl;
    }
    return 0;
}
int result(string &Q){
    int n=Q.size();
    foe(i,0,n-1){
        if(Q[i]=='y') Q[i]='0';
        else Q[i]='1';
    }
    int res=0;
    foe(i,0,n-1){
        res=res*2+Q[i]-'0';
    }
    return res+1;
}