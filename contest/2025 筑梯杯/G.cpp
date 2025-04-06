#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define endl '\n'
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PII pair<int,int>
#define int long long

struct an{
    int n,i,b;
};

bool comp(an x,an y){
    if(x.n<y.n)return true;
    else return false;
}

an a[100003];
int b[100003];
signed main(){
	IOS;
    long long n,m,j,k,v,i;
	int T=1;
//	cin>>T;
	while(T--){
        cin>>n;
        foe(i,0,n){
            cin>>a[i].n;
            a[i].i=i+1;
        }
        foe(i,0,n){
            cin>>m;
            a[i].b=m;
        }
        sort(a,a+n,comp);
            for(j=0;j<n;j++){
                    v=j%2;
                    k=j/2;
                    if(v){
                        if(a[j].b<=k){
                            b[a[j].i]=0;
                        }else{
                            b[a[j].i]=(a[j].b-k)*2-1;
                        }
                    }else{
                        if(a[j].b<=k){
                            b[a[j].i]=0;
                        }else{
                            b[a[j].i]=(a[j].b-k)*2;
                        }
                    }
            }
            for(i=1;i<=n;i++)
            if(i==1)
            cout<<b[i];
            else cout<<" "<<b[i];
        }
    }
