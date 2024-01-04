#include<stdio.h>
#include<string.h>
int main(){
    char s1[200001]={0},s2[100001]={0};
    while(scanf("%s%s",s1,s2)!=EOF){
        int l1=strlen(s1),l2=strlen(s2);
        strcat(s1,s1);
        if(strstr(s1,s2)!=NULL&&l1>=l2)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}