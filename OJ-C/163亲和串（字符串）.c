#include<stdio.h>
#include<string.h>
void ringOne(char* str);
int main(){
    char s1[100001]={0},s2[100001]={0};
    while(scanf("%s%s",s1,s2)!=EOF){
        int len=strlen(s1);
        int flag=0;
        for(int i=1;i<=len;i++){
            if(strstr(s1,s2)!=NULL){
                flag=1;
                break;
            }
            ringOne(s1);
        }
        if(flag)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
void ringOne(char* str){
    int len=strlen(str);
    char t=str[len-1];
    for(int i=len-1;i>=1;i--){
        str[i]=str[i-1];
    }
    str[0]=t;
}