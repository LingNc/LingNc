#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int main(){
    string str;
    int num=0;
    while(1){
        cin>>str;
        if(str.empty()==false&&str[0]!='.'){
            num++;
        }
        if(*(str.end())!=' ') break;
    }
    cout<<num<<endl;
    return 0;
}