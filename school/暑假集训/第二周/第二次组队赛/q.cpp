#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

long long a,c,d,e,f,t,m[100005],n[100005],x[100005],y[100005];
double b;
void dps(long long p,long long sum,long long ans){
    long long z=0;
    long long x1,x2;
    x1=sum;
    x2=ans;

    for(int i=1;i<a;i++){
        if(m[i]==p&&y[n[i]]==0){
            z=1;
            y[m[i]]=1;
            if(15%x[n[i]]==0)
                x1=x1+15/x[n[i]];
            else{

                if(x2%x[n[i]]!=0){
                    x1=x1*x[n[i]]+15*x2;
                    x2=x2*x[n[i]];
                }
                else x1=x1+(x2/x[n[i]])*15;
            }
            dps(n[i],x1,x2);
            y[m[i]]=0;
            x1=sum;
            x2=ans;
        }
        if(n[i]==p&&y[m[i]]==0){
            z=1;
            y[n[i]]=1;
            if(15%x[m[i]]==0)
                x1=x1+15/x[m[i]];
            else{

                if(x2%x[m[i]]!=0){
                    x1=x1*x[m[i]]+15*x2;
                    x2=x2*x[m[i]];                
}
                else x1=x1+(x2/x[m[i]])*15;
            }
            dps(m[i],x1,x2);
            y[n[i]]=0;
            x1=sum;
            x2=ans;
        }
    }
    if(z==0){
        if(b<double(x1/x2)){
            b=double(x1)/double(x2);

            e=x1;
            c=x2;
        }
        return;
    }

}
int gcd(int x1,int x2){
    if(x1%x2==0)
        return x2;
    return gcd(x2,x1%x2);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>t;
    while(t--){
        cin>>a;
        c=0;
        e=0;
        b=0;
        for(int i=1;i<a;i++){
            cin>>m[i]>>n[i];
        }
        for(int i=1;i<=a;i++){
            cin>>x[i];
            y[i]=0;
        }
        if(x[1]%15==0){
            dps(1,15/x[1],1);
        }
        else { dps(1,15,x[1]); }
        f=gcd(e,c);
        e=e/f;
        c=c/f;
        cout<<e<<"/"<<c<<endl;
    }



    return 0;
}