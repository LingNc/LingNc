#include<stdio.h>
#include<string.h>
int main(){
	char num[14]={'\0'};
    char qian[5]="0591-";
    int flag=1;
    gets(num);
    for(int i=0;i<=12;i++){
        if(i<=4&&qian[i]!=num[i]) flag=0;
        if(i>4&&(num[i]<'0'||num[i]>'9')) flag=0;
    }
    if(flag==0)
        printf("no\n");
    else
        printf("yes\n");
    return 0;
}