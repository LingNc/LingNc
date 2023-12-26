#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char* decimal(char* p);
int main(){
    char num[101]={0};
    cin>>num;
    if(decimal(num)==NULL)
        cout<<"No decimal part"<<'\n';
    else
        cout<<'0'<<decimal(num)<<'\n';
    return 0;
}
char* decimal(char* p){
    /*将字符串p表示的实数的自小数点开始的小数部分存入一个字符串，
    并由函数返回，若p为“123.456”，则返回的字符串为“.456”。
    若小数部分为0,返回空指针NULL。*/
    p=strchr(p,'.');
    int len=strlen(p);
    for(int i=len-1;i>=1;i--){
        if(p[i]=='0')
            p[i]=0;
        else
            break;
    }
    if(p[1]==0)
        return NULL;
    else
        return p;
}