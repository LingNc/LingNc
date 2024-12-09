#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define endl '\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define string char
using namespace std;
void Swap(string *x,string *y){
    auto t=*x;
    *x=*y;
    *y=t;
}
string* reverse(string *begin){
    int len=strlen(begin)-1;
    foe(i,0,len/2)
        Swap(begin+i,begin+len-i);
    return begin;
}
int main(){
    string str[100]={ 0 };
    while(scanf("%s",str)!=EOF){
        cout<<reverse(str)<<' ';
    }
}