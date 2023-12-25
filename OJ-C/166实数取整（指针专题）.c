#include<stdio.h>
char* rounding(char* p);
int main(){
    char num[101]={'\0'};
    gets(num);
    char* p=rounding(num);
    puts(p);
    return 0;
}
char* rounding(char* p){
    //将字符串p表示的实数取整后生成新的字符串，并由函数返回
    int flag=0;
    for(int i=0;i<=100;i++){
        if(p[i]=='.'){
            flag=1;
            p[i]=0;
        }
        if(flag==1) p[i]=0;
    }
    int start=0;
    if(p[0]=='0'){
        for(int i=0;i<=100;i++){
            if(p[i]=='0'&&((p[i+1]>'0'&&p[i+1]<='9')||p[i+1]==0)){
                if(p[0]=='0'&&p[1]!=0){
                    start=(p[i+1]==0)?i:i+1;
                    int i=0;
                    while(i+start<=100){
                        p[i]=p[i+start];
                        p[i+start]=0;
                        i++;
                    }
                    break;
                }

            }
        }
    }
    if(p[0]=='-'&&p[1]=='0'){
        p[0]='0';
        p[1]=0;
    }
    return p;
}