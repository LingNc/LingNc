#include<iostream>
#define endl '\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

void  Swap(int *x,int *y){
    auto t=*x;
    *x=*y;
    *y=t;
}
void reverse(int *begin,int len){
    len--;
    foe(i,0,len/2)
        Swap(begin+i,begin+len-i);
}
int main(){
    int a[11]={0};
    foe(i,0,9) cin>>a[i];
    int x,y;
    cin>>x>>y;
    reverse(a+x-1,y);
    foe(i,0,9){
        cout<<a[i]<<' ';
    }
    return 0;
}