#include"A.cpp"
typedef struct Combine{
    //N最大，p模
    int N,p;
    vector<int> inv,fac;
    //N 最大数量，p取模的模数
    Combine(int _N,int _p):inv(_N,0),fac(_N,0){N=_N,p=_p;}
    //快速幂    
    int quickPow(int a,int b){
        int ans=1;
        while(b){
            if(b&1)
                ans=(ans*a)%p;
            b>>=1;
            a=(a*a)%p;
        }
        return ans;
    }
    //初始化
    void init(){
        fac[0]=1;
        for(int i=1;i<N;i++){
            fac[i]=fac[i-1]*i%p;
        }
        inv[N-1]=quickPow(fac[N-1],p-2);
        for(int i=N-2;i>=0;i--){
            inv[i]=inv[i+1]*(i+1)%p;
        }
    }
    //逆元求组合数 m中选n个
    int com(int m,int n){
        if(n>m) return 0;
        if(n==0) return 1;
        return fac[m]*inv[n]%p*inv[m-n]%p;
    }
    //卢斯卡定理 当p小于m时用
    int lucas(int m,int n){
        if(n==0) return 1;
        return lucas(m/p,n/p)*com(m%p,n%p)%p;
    }
    //求组合数
    int C(int m,int n){
        if(p>m) return lucas(m,n);
        else return com(m,n);
    }
}combine;