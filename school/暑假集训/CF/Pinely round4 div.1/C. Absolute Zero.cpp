#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define int long long
using i64=long long;
using namespace std;

const int N=1e5+10;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    foe(i,0,n-1){
        cin>>a[i];
    }
    int step=0;
    vector<int> b(n-1);
    map<int,int> c;
    vector<int> ans(41);
    while(++step){
        //大于40
        if(step>40){
            cout<<-1<<endl;
            return ;
        }
        //单输入
        if(a.size()==1){
            if(a[0]!=0)
                cout<<1<<endl<<a[0]<<endl;
            else cout<<0<<endl<<endl;
            return;
        }
        //排序
        sort(a.begin(),a.end());
        foe(i,0,n-1-1){
            //求差分
            b[i]=a[i+1]-a[i];
            //存在奇数差
            if(b[i]%2==1){
                cout<<-1<<endl;
                return ;
            }
            //求差数量
            c[b[i]]++;
        }
        //找差最多的数量的位置的数
        int max_num=-1;
        for(auto &i:c){
            if(i.first!=0)
                max_num=max(i.second,max_num);
        }
        int l=0,r=0;
        foe(i,0,n-1){
            if(c[b[i]]==max_num){
                l=i;
                break;
            }
        }
        fod(i,n-2,0){
            if(c[b[i]]==max_num){
                r=i;
                break;
            }
        }
        //求两个差最多的数的距离
        int q=(a[l]+a[r+1])/2;
        ans[step-1]=q;
        //新数组
        foe(i,0,n-1){
            a[i]=abs(a[i]-q);
        }
        c.clear();
        //判断是否继续
        int flag=true;
        foe(i,0,n-1){
            if(a[i]!=0){
                flag=false;
                break;
            }
        }
        //求出全零数组
        if(!flag) continue;
        if(ans[0]==0) step--;
        cout<<step<<endl;
        foe(i,0,step-1)
            if(ans[i]!=0) cout<<ans[i]<<' ';
        cout<<endl;
        return ;
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}