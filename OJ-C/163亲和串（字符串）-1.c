#include<stdio.h>
#include<string.h>
int main(){
    char s1[100001]={0},s2[100001]={0},s3[200001]={0};
    while(scanf("%s%s",s1,s2)!=EOF){
        strcat(s3,s1);
        strcat(s3,s1);
        int len1=strlen(s1),len2=strlen(s2);
        if(len1<len2){
            puts("no");
        }
        else{
            if(strstr(s3,s2)!=NULL){
                puts("yes");
            }
            else
                puts("no");
        }
    }
    return 0;
}