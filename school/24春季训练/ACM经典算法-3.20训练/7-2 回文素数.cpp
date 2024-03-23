#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
bool isprime(int x);
bool isTxT(int x);
void solve();
int main(){
    solve();
    return 0;
}
void solve(){
    int A,B;
    cin>>A>>B;
    int sum=0,num[B-A];
    foe(i,A,B){
        if(isprime(i))
            if(isTxT(i)){
                num[sum]=i;
                sum++;
            }
    }
    cout<<sum<<endl;
    foe(i,0,sum-1)
        cout<<num[i]<<endl;
}
bool isTxT(int x){
    int origin=x,sum=0;
    while(x){
        sum*=10;
        sum+=x%10;
        x/=10;
    }
    return (sum==origin)?1:0;
}
bool isprime(int x){
    if(x<=3) return (x<=1)?0:1;
    int sq=sqrt(x);
    foe(i,2,sq)
        if(x%i==0) return 0;
    return 1;
}