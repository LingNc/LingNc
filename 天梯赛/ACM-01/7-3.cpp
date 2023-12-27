#include<cstdio>
#include<cstring>
using namespace std;

bool j(char* stk,int M,int len);
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    getchar();
    char stk[101]={'\0'};
    while(N--){
        scanf("%s",&stk);
        int len=strlen(stk);
        if(j(stk,M,len)){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
bool j(char* stk,int M,int len){
    int num=0;
    char *ptr=stk;

    for(int i=0;i<=len-1;i++){
        if(*ptr=='S')
            num++;
        else
            num--;

        if(num<0||num>M)
            return 0;

        ptr++;
    }
    if(num!=0)
        return 0;
    else
        return 1;
}