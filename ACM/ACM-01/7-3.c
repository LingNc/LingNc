#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int j(char* stk,int M);
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    getchar();
    char stk[M+1];
    memset(stk,0,M*sizeof(char));
    while(N--){
        scanf("%[^\n]%*c",stk);
        if(j(stk,M)){
            puts("YES");
        }
        else{
            puts("NO");
        } 
    }
    return 0;
}
int j(char* stk,int M){
    if(stk[M]!=0)
        return 0;
    int len=strlen(stk);
    int num=0;
    char* ptr=stk;

    for(int i=0;i<=len-1;i++){
        if(*ptr=='S'){
            num++;
        }
        else{
            num--;
        }
        if(num<0) return 0;
        if((i<len-1)&&num==0) return 0;
        ptr++;
    }
    if(num!=0)
        return 0;
    else    
        return 1;
}
