#include<stdio.h>
#include<string.h>
int main(){
    char article[1002]={'\0'};
    gets(article);
    int n=strlen(article);
    int num=0;
    char flag=0;
    for(int i=0;i<=n-1;i++){
        if(flag==0&&article[i]>='0'&&article[i]<='9'){
            if(article[i]=='0'){
                num++;
                continue;
            }
            else{
                flag=1;
                num++;
            }
        }
        else if(flag==1&&(article[i]<'0'||article[i]>'9'))
            flag=0;
    }
    printf("%d",num);
    return 0;
}