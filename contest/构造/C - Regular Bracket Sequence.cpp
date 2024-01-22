#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    char s1[101]={0};
    bool res;
    cin>>t;
    while(t--){
        cin>>s1;
        int num=0,len=strlen(s1);
        for(int i=0;i<=len-1;i++){
            if(s1[i]=='?') num++;
            if(s1[i]=='/'){
                s1[i]='?';
                num++;
            }
        }
        if(num%2==1) res=false;
        else{
            char *l=strchr(s1,'(');
            char *r=strchr(s1,')');
            char *s_end=&s1[len-1];
            if(l<r){
                *l='x';*r='x';
                res=true;
            }
            else{
                char *pl=l+1;
                int num=0;
                while(pl<=s_end){
                    if(*pl=='?'){
                        num+=1;
                        break;
                    }
                    pl++;
                }
                char *pr=r-1;
                while(pr>=s1){
                    if(*pr=='?'){
                        num+=1;
                        break;
                    }
                    pr--;
                }
                if(num==2) res=true;
                else res=false;
            }
        }
        if(res)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}