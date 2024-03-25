#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<stack>
#include<queue>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int num,max,S;
    cin>>num>>max>>S;
    getchar();
    string F[num];
    foe(i,0,num-1){
        cin>>F[i];
    }
    stack<char> Stk;
    int number=0;
    while(1){
        cin>>number;
        if(number==-1) break;
        if(number!=0){
            if(F[number-1].empty()==true) continue;
            if(Stk.size()==S){
                cout<<Stk.top();
                Stk.pop();
            }
            auto it=F[number-1].begin();
            Stk.push(*it);
            F[number-1].erase(it);
        }
        else{
            if(Stk.empty()==true) continue;
            cout<<Stk.top();
            Stk.pop();
        }
    }
    return 0;
}