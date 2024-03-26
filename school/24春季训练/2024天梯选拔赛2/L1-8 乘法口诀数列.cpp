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
    vector<int> num;
    int n;
    foe(i,0,1){
        cin>>n;
        num.push_back(n);
    }
    cin>>n;
    int i=0,m=0;
    while(num.size()<=n-1){
        m=num[i]*num[i+1];
        if(m<=9) num.push_back(m);
        else{
            vector<int> s;
            while(m){
                s.push_back(m%10);
                m/=10;
            }
            for(int i=s.size()-1;i>=0;i--){
                num.push_back(s[i]);
            }
        }
        i++;
    }
    foe(i,0,n-1){
        cout<<num[i];
        if(i!=n-1) cout<<' ';
    }
    return 0;
}