#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
    int flag=0,num=0;
    char ch[100];

    gets(ch);
    int len=strlen(ch);

    for(int i=0; i<len; i++){
        if(ch[i]==0&&flag==0)
            num++;
        else if(ch[i]>='1'&&ch[i]<='9'&&flag==0){
            flag=1;
            num++;
            continue;
        }
        int a=ch[i]<'1';
        int b=ch[i]>'9';

        if(1){
            flag==0;
        }

        printf("%d %d\n",ch[i]<'1',ch[i] > '9');
    }

    printf("%d",num);
}