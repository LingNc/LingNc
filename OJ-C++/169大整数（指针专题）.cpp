#include<bits/stdc++.h>
using namespace std;

bool cmp(char** a,char** b){
    return strcmp(*a,*b)<0;
}
int main(){
    char *ptr[3]={0};
    for(int i=0;i<=2;i++){
        ptr[i]=(char*)malloc(101*sizeof(char));
        memset(ptr[i],0,sizeof(char));
    }
    //char num[3][101]={0};
    for(int i=0;i<=2;i++){
        cin>>ptr[i];
    }
    sort(ptr,ptr+2,cmp);
    for(int i=0;i<=2;i++){
        cout<<ptr[i]<<'\n';
        //printf("%0x ",ptr+i);
    }
    return 0;
}
int acmp(char* a,char* b){
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
        return acmp(a+1,b+1);
    }
}