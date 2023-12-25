#include <stdio.h>
#include <string.h>

char* rounding(char* p);

int main(void){
    char ch[1000]={0};

    gets(ch);

    char* flag=rounding(ch);

    if(flag==NULL)
        printf("0\n");
    else
        printf("%s\n",flag);
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
    return p;
}