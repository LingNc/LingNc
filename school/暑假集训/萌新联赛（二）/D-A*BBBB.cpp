#include<bits/stdc++.h>
#define ll long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;
// C = A + B, A >= 0, B >= 0
vector<int> add(vector<int> A, vector<int> B)
{
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}
//高精度乘法
// C = A * bbbbbbbbbbbbbbbbbb(n个), A >= 0, b >= 0
vector<int> mul(vector<int> &A,int b,int n){
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size()||t;i++){
        if(i<A.size()){
            t+=A[i]*b;
            C.push_back(t%10);
            t/=10;
        }
    }
    while(C.size()>1&&C.back()==0){
        C.pop_back();
    }
    vector<int> D(C);
    foe(i,1,n-1){
        D.insert(D.begin(),0);
        C=add(C,D);
    }
    return C;
}
void solve(){
    vector<int> A,B;
    char ch;
    while(1){
        scanf("%c",&ch);
        if(ch==' ') break;
        A.push_back(ch-'0');
    }
    while(1){
        scanf("%c",&ch);
        if(ch=='\n') break;
        B.push_back(ch-'0');
    }
    reverse(A.begin(),A.end());
    int n=B.size();
    int b=*B.begin();

    vector<int> C=mul(A,b,n);
    reverse(C.begin(),C.end());
    foe(i,0,C.size()-1){
        cout<<C[i];
    }
    cout<<endl;
}

signed main(){
    int T=1;
    cin>>T;
    getchar();
    while(T--){
        solve();
    }
    return 0;
}
