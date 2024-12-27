#include<bits/stdc++.h>
#define endl '\n'
#define foe(i,a,b) for(auto i=(a);i<=(b);i++)

using namespace std;

bool is_out(int k,int x,int y){
    if(x<=2*k-1){
        if(y>x+k||y<-x+k-1||y<x-k) return true;
        else return false;
    }
    else{
        if(y>-x+5*k-1||y<x-3*k||y<-x+3*k-1) return true;
        else return false;
    }
}


int main(){
    int n;
    cin>>n;
    char a,b;
    cin>>a>>b;
    foe(i,0,3*n-1){
        foe(j,0,4*n-1){
            if(!is_out(n,j,i)) cout<<b;
            else cout<<a;
        }
        cout<<endl;
    }
    return 0;
}