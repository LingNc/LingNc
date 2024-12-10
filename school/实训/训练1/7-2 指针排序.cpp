#include<iostream>
#define endl '\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

void  Swap(int *x,int *y){
    auto t=*x;
    *x=*y;
    *y=t;
}
int main(){
    int a[3];
    foe(i,0,2) cin>>a[i];
    foe(i,0,2)foe(j,0,2){
        if(a[i]>a[j]) Swap(&a[i],&a[j]);
    }
    foe(i,0,1) cout<<a[i]<<',';
    cout<<a[2];
    return 0;
}