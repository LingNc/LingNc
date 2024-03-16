#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
#define endl '\n'

using namespace std;

ll N,C;

bool check(ll min_dis,ll *loc,ll *cha);

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>N>>C;
    ll loc[N+1]={0},cha[N+1]={0};
    for(int i=1;i<=N;i++)
        cin>>loc[i];
    sort(loc,loc+N);
    for(int i=1;i<=N;i++){
        cha[i]=loc[i]-loc[i-1];
    }
    ll ml=0,mr=loc[N],mid;
    while(ml+1<mr){
        mid=(ml+mr)>>1;
        if(check(mid,loc,cha)==1)
            mr=mid;
        else
            ml=mid;
    }
    cout<<mr;
    return 0;
}
bool check(ll min_dis,ll loc[],ll cha[]){
    ll num=0,dis=0;
    for(int i=0;i<=N-1;i++){
        if(dis>=min_dis){
            num++;
            dis=cha[i+1];
        }
        else
            dis+=cha[i+1];
    }
    if(dis>=min_dis) num++;
    if(num>=C) return 0;
    else return 1;
}