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
    char s[100000]={0};
    scanf("%[^\n]%*c",s);
    string str=s;
    str.insert(str.begin(),' ');
    int num=0;
    for(auto i=str.begin();i<=str.end()-2;i++){
        if(*i==' '&&*(i+1)!=' '){
            num++;
        }
    }
    cout<<num<<endl;
    return 0;
}