#include<iostream>
#include<algorithm>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int solve(int n,int k){
    int sum=0;
    if(k==0){
        sum+=0;
    }
    else if(k<=n){
        sum+=1;
        k=max(0,k-n);
        n--;
    }
    else{
        sum+=1;
        k-=n;
        n--;
        while(k>0){
            foe(i,1,2){
                sum+=1;
                k=max(0,k-n);
                if(k==0) break;
            }
            n--;
        }
    }
    return sum;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    cin>>T;
    int n,k;
    while(T--){
        cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }
    return 0;
}