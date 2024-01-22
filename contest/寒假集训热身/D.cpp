#include<iostream>
#include<algorithm>
using namespace std;
typedef struct{
    double res;
    double J;
    double F;
}FJ;
bool cmp(FJ a,FJ b){
    return a.res>b.res;
}
int main(){
    int M,N;
    while(1){
        cin>>M>>N;
        FJ res[1001]={0};
        if(M==-1&&N==-1) break;
        double JavaBean=0;
        for(int i=0;i<=N-1;i++){
            cin>>res[i].J>>res[i].F;
            res[i].res=res[i].J/res[i].F;
        }
        sort(res,res+N,cmp);
        for(int i=0;i<=N-1;i++){
            if(res[i].F<M){
                M-=res[i].F;
                JavaBean+=res[i].J;
            }
            else{
                JavaBean+=M*res[i].res;
                break;
            }
        }
        printf("%.3lf\n",JavaBean);
    }
    return 0;
}