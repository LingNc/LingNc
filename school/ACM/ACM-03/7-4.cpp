#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
void pri_num(int space,int number,int n);
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n-1;i++){
        pri_num(i,n-i,2*(n-i)-1);
    }
    for(int i=n-2;i>=0;i--){
        pri_num(i,n-i,2*(n-i)-1);
    }
    return 0;
}
void pri_num(int space,int number,int n){
    for(int i=1;i<=space;i++) putchar(' ');
    for(int i=1;i<=n;i++) putchar(number+'0');
    putchar('\n');
}