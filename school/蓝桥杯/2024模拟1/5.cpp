#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a={ 9226,4690,4873,1285,4624,1596,6982,590,8806,121,8399,8526,5426,64,9655,7705,3929,3588,7397,8020,1311,5676,3469,2325,1226,8203,9524,3648,5278,8647 };

int sum(int V){
    int res=0;
    for(int i=0;i<a.size();i++){
        auto it=a[i];
        int num=it^V;
        res+=num*num;
    }
    return res;
}
void solve(){
    int min_res=INT64_MAX;
    int k=0;
    for(int i=0;i<=1000000000;i++){
        int num=sum(i);
        if(num<min_res){
            min_res=num;
            k++;
            cout<<k<<' '<<min_res<<endl;
        }
    }
    cout<<min_res;
}
int main(){
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
