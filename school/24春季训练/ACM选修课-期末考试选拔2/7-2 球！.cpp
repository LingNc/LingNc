#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)
//priority_queue
using namespace std;
void priA(vector<int> &A){
    foe(i,0,A.size()-1){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}

void solve(){
    ios::sync_with_stdio(0),cin.tie(0);
    int N,A;
    cin>>N;
    vector<int> M;
    foe(i,1,N){
        cin>>A;
        if(M.size()==0){
            M.push_back(A);
            //priA(M);

        }
        else if(*M.rbegin()!=A){
            M.push_back(A);
            //priA(M);
        }
        else if(*M.rbegin()==A){
            (*M.rbegin())++;
            //priA(M);
            while(1){
                if(*(M.end()-1)==*(M.end()-2)){
                    (*(M.end()-2))++;
                    M.erase(M.end()-1);
                }
                else{
                    break;
                }
            }
            //priA(M);

        }
    }
    cout<<M.size()<<endl;

}
int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
