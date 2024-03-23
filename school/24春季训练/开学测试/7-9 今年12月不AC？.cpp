#include<iostream>
#include<algorithm>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;

typedef struct{
    int start,end;
}time_data;
bool cmp(time_data a,time_data b){
    return a.end < b.end;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    time_data  time[n];
    foe(i,0,n-1){
        cin>>time[i].start>>time[i].end;
    }
    getchar();
    sort(time,time+n,cmp);
    int result=1;
    int start=time[1].start,end=time[0].end;
    foe(i,0,n-2){
        if(end<=start){
            result++;
            end=time[i+1].end;
        }
        start=time[i+2].start;
    }
    cout<<result<<endl;
    return 0;
}