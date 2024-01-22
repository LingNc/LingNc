#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
typedef struct{
    char str[13];
    int num;
}colour;
int main(){
    while(1){
        int n;
        std::cin>>n;
        if(n==0) break;
        colour str[1010];
        int k=0;
        memset(str,0,sizeof(str));
        for(int i=0;i<=n-1;i++){
            char s[16]={0};
            std::cin>>s;
            int flag=1;
            for(int j=0;j<=i;j++){
                if(strcmp(str[j].str,s)==0){
                    str[j].num++;
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                strcpy(str[k].str,s);
                k++;
            }
        }
        int max=INT_MIN,k2=0;
        for(int m=0;m<=n-1;m++){
            if(str[m].num>max){
                max=str[m].num;
                k2=m;
            }
        }
        puts(str[k2].str);
    }
    return 0;
}