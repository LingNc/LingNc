#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>list(n+1,0);
    foe(i,1,n)
        list[i]=i;
    int last=0,now,last_p=1;
    foe(i,1,m){
        int p,now;
        cin>>p>>now;
        if(p){
            if(now<last&&last_p==1) sort(list.begin()+now-1,list.begin()+last);
            else if(now<last&&last_p==0) sort(list.begin()+)
        }
    }
    return 0;
}