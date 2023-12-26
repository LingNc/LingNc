#include<bits/stdc++.h>
using namespace std;

bool m_cmp(char* a,char *b);
int main(){
    char num[3][101]={0};
    for(int i=0;i<=2;i++){
        cin>>num[i];
    }
    sort(num[0],num[2],m_cmp);
    for(int i=0;i<=2;i++){
        cout<<num[i]<<'\n';
    }
    return 0;
}
int cmp(char* a,char* b){
    //若大整数a大于b，返回1；
    //若a小于b，返回-1；
    // 若a与b相等，返回0
    if((*a==0||*b==0)||*a!=*b){
        if(*a==*b)
            return 0;
        else
            return ((*a-*b)>0)?1:-1;
    }
    else{
        return cmp(a+1,b+1);
    }
}
bool m_cmp(char* a,char *b){
    return -cmp(a,b);
}