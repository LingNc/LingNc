#include<iostream>
#include<algorithm>
#include<queue>
#define int long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int solve(int n,int m){
    priority_queue<int> q;
    int num;
    foe(i,1,n){
        cin>>num;
        q.push(num);
    }
    int sum=0,f=0,last=-1,start=-1;
    int max_res=-1;
    while(q.size()){
        int t=q.top();
        q.pop();

        if(t<=m){
            if(start-t==0){
                sum+=t;
                if(sum>m){
                    sum-=t;
                    max_res=max(max_res,sum);
                    //new
                    sum=t;
                    start=t;
                }
            }
            else if(start-t==1){
                if(last-t==1){
                    f++;
                    if(f==2){
                        f=0;
                        max_res=max(max_res,sum);
                        sum=t;
                        start=t;
                    }
                    else{
                        sum+=t;
                        if(sum>m){
                            sum-=1+t;
                        }
                        if(sum==m) max_res=max(max_res,sum);
                    }
                }
                else if(last-t==0){
                    sum+=t;
                    if(sum>m){
                        sum-=1+t;
                    }
                    if(sum==m) max_res=max(max_res,sum);
                }
            }
            else if(start-t>1){
                f=0;
                max_res=max(max_res,sum);
                sum=t;
                start=t;
            }
            else if(start-t<0){
                sum+=t;
                start=t;
            }
            last=t;
        }
    }
    return max(max_res,sum);
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    cin>>T;
    int n,m;
    while(T--){
        cin>>n>>m;
        cout<<solve(n,m)<<endl;
    }
    return 0;
}