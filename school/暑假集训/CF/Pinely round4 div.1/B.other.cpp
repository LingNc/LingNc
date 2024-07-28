#include<bits/stdc++.h>
using namespace std;
long long m[200005],n[200005];
int main(){
    long long a,b,c,d,e,f,i,j,t;
    cin>>t;
    while(t--){
        cin>>a;
        b=0;
        c=0;
        d=0;
        for(i=0;i<a-1;i++){
            cin>>m[i];
        }
        if(a>=3){
            for(i=1;i<a-1;i++){
                c=m[i+1]&m[i-1];
                d=c&m[i];
                if(c!=d){
                    b=1;

                }
            }
        }e=0;
        f=0;
        if(b==1)cout<<"-1"<<endl;
        else{
            cout<<m[0]<<" ";
            for(i=1;i<a;i++){
                e=m[i]&m[i-1];
                f=m[i]+m[i-1]-e;
                cout<<f<<" ";
            }
            cout<<endl;
        }
    }





    return 0;
}
