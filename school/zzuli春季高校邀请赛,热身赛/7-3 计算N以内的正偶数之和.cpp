#include<iostream>
#include<algorithm>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int main(){
    int N;
    cin>>N;
    int res=0;
    if(N%2==0)
        res=((N/2)*(1+N/2));
    else
        res=((N-1)/2)*(1+(N-1)/2);
    cout<<"sum = "<<res;
    return 0;
}