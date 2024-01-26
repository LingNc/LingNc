#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> num(n,0),M(n,0);
    int max1=1,max2=1;
    cin>>num[0];
    for(int i=1;i<=n-1;i++){
        cin>>num[i];
        if(num[i]>=num[i-1])
            max2++;
        else{
            if(max2>max1)
                max1=max2;
            max2=1;
        }
    }
    max2=max(max1,max2);
    cout<<max2;
    return 0;
}