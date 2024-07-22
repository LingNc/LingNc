#include<iostream>
#include<algorithm>
#define ll long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

const int N=1e6+10;

int e[N],ne[N],idx=1,head=-1,idx=0;

void init(){
    head=-1;
    idx=0;
}

void add_head(int x){
    e[idx]=x;
    ne[idx]=head;
    
    head=idx;
    
}

int main(){

    return 0;
}