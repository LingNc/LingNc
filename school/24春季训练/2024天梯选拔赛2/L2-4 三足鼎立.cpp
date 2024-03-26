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
    int n,P;
    cin>>n>>P;
    vector<int> p(n+1,0);
    p[0]=P;
    foe(i,1,n){
        cin>>p[i];
    }
    //大模拟
    /*
    foe(j,1,n-1)
        foe(k,j+1,n){
            if(p[j]+p[k]>p[0]&&p[0]+p[j]>p[k]&&p[0]+p[k]>p[j]){
                num++;
            }
        }
    */
    int num=0;
    sort(p.begin(),p.end());
    foe(i,1,n){
        
    }
    cout<<num<<endl;
    return 0;
}