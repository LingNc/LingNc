#include<iostream>
#include<algorithm>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
#define endl '\n'

using namespace std;

int N,C;
int a[100000+10]={ 0 };

bool check(int mid){
    int pre=a[0];
    int sum=1;
    foe(i,1,N-1){
        if(a[i]-pre>=mid){
            pre=a[i];
            sum++;
            if(sum>=C) return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>N>>C;
    foe(i,0,N-1){
        cin>>a[i];
    }
    sort(a,a+N);
    int l=0,r=a[N-1]-a[0];

    while(l+1<r){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<l<<endl;
    return 0;
}