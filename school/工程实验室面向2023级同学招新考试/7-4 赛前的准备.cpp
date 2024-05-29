#include<iostream>
#include<algorithm>
#include<climits>
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define endl '\n'
using namespace std;

void solve(){
    int m,n;
    cin>>m>>n;
    int sum=0;
    int nD=0,nM=0,nS=0;
    char temp;
    foe(i,1,n){
        cin>>temp;
        switch(temp){
            case 'D':
                nD++;
                break;
            case 'M':
                nM++;
                break;
            case 'S':
                nS++;
                break;
        }
    }
    //sum+=nD*((m%2!=0)?(m/2+1):m/2)+nM*((m*2%3!=0)?(m*2/3+1):m*2/3)+nS*m;
    sum+=nD*(m/2)+nM*(m*2/3)+nS*m;
    cout<<sum<<endl;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}