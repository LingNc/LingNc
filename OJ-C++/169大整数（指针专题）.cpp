#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int cmp(char* a,char* b);
int acmp(char* a,char *b){
    return cmp(a,b)<=0;
}
int main(){
    char* ptr[3]={0};
    for(int i=0;i<=2;i++){
        ptr[i]=(char*)malloc(101*sizeof(char));
        memset(ptr[i],0,sizeof(char));
    }
    //char num[3][101]={0};
    for(int i=0;i<=2;i++){
        cin>>ptr[i];
    }
    sort(ptr,ptr+3,acmp);
    for(int i=0;i<=2;i++){
        cout<<ptr[i]<<'\n';
        //printf("%0x ",ptr+i);
    }
    return 0;
}
int mcmp(char* a,char* b){
    if(*a!=*b)
        return (*a>*b)?1:-1;
    else{
        if(*(a+1)==0||*(b+1)==0)
            return 0;
        return mcmp(a+1,b+1);
    }
}
int cmp(char* a,char* b){
    //若大整数a大于b，返回1；
    //若a小于b，返回-1；
    // 若a与b相等，返回0
    int la=strlen(a)-1,lb=strlen(b)-1;
    if(la!=lb)
        return (la>lb)?1:-1;
    else
        return mcmp(a,b);
}