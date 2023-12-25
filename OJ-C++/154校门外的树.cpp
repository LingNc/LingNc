#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    while(N--){
        int L,M;
        cin>>L>>M;
        int list[L+1];
        for(int i=0;i<=L;i++){
            list[i]=0;
        }
        while(M--){
            int start,end;
            cin>>start>>end;
            list[start]++;
            list[end+1]--;
        }
        for(int i=1;i<=L;i++){
            list[i]+=list[i-1];
        }
        for(int i=0;i<=L;i++){
            list[i]=(list[i]>=1)?1:0;
        }
        int sum=0;
        for(int i=0;i<=L;i++){
            sum+=list[i];
        }
        cout<<L+1-sum<<endl;
    }
    return 0;
}