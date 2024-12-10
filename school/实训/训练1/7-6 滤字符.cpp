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
string *reverse(string *begin){
    int len=strlen(begin)-1;
    foe(i,0,len/2)
        Swap(begin+i,begin+len-i);
    return begin;
}
size_t find(string str[],char ch){
    size_t len=strlen(str);
    if(len==0) return 0;
    foe(i,0,len-1) if(str[i]==ch) return i;
    return len;
}
string *earse(string str[],size_t pos){
    size_t len=strlen(str);
    if(len==0) return str;
    foe(i,pos,len-1)
        str[i]=str[i+1];
    return str;
}
string *earse(string str[],char ch){
    size_t len=strlen(str);
    if(len==0) return str;
    while(1){
        auto res=find(str,ch);
        if(res==len) break;
        earse(str,res);
        len--;
    }
    return str;
}
int main(){
    int n;
    cin>>n;
    string str[200]={ 0 };
    while(n--){
        cin>>str;
        char e_ch;
        cin>>e_ch;
        earse(str,e_ch);
        if(strlen(str))
            cout<<str<<endl;
        else
            cout<<"NULL"<<endl;
    }
}