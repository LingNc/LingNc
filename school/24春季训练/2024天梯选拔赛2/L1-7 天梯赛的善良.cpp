#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<climits>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> p;
    int min=INT_MAX,max=INT_MIN;
    int k;
    foe(i,0,n-1){
        cin>>k;
        p.push_back(k);
        if(min>p[i]) min=p[i];
        if(max<p[i]) max=p[i];
    }
    sort(p.begin(),p.end());
    int min_num=0,max_num=0;
    foe(i,0,n-1){
        if(p[i]!=min) break;
        min_num++;
    }
    for(int i=n-1;i>=0;i--){
        if(p[i]!=max) break;
        max_num++;
    }
    cout<<min<<' '<<min_num<<endl;
    cout<<max<<' '<<max_num<<endl;
    return 0;
}