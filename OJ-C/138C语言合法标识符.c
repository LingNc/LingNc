#include<stdio.h>
#include<string.h>
int main(){
    char str[50];
    gets(str);
    int n=strlen(str);
    int flag=0;
    for(int i=0;i<=n-1;i++){
        if((str[i]<='z'&&str[i]>='a')
        ||(str[i]<='Z'&&str[i]>='A')
        ||(str[i]>='0'&&str[i]<='9')
        ||str[i]=='_'){
            if(i==0&&(str[i]>='0'&&str[i]<='9'))
                goto end;
            continue;
        }
        else{
            end:
            printf("no");
            return 0;
        }
    }
    printf("yes");
    return 0;
}