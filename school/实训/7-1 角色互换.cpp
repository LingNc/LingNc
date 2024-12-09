#include<iostream>
#define endl '\n'
using namespace std;

void  Swap(int *x,int *y){
    auto t=*x;
    *x=*y;
    *y=t;
}
int main(){
    int a,b;
    cin>>a>>b;

    Swap(&a,&b);
    cout<<a<<' '<<b<<endl;;
    return 0;
}