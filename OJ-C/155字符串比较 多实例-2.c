#include<stdio.h>
#include<string.h>
int m_strcmp(char* str1,char* str2);
int main(){
    char str1[10001]={0},str2[10001]={0};
    while(scanf("%s%s",str1,str2)!=EOF){
        //char str1[]="AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
        int flag=m_strcmp(str1,str2);
        if(flag<0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
int m_strcmp(char* str1,char* str2){
    int len1=strlen(str1);
    int len2=strlen(str2);

    for(int i=0;i<=len1-1;i++){
        if(str1[i]>='a'&&str1[i]<='z'){
            str1[i]=str1[i]*2-63;
        }
        else{
            str1[i]*=2;
        }
        //printf("%d ",str1[i]);
    }
    for(int i=0;i<=len2-1;i++){
        if(str2[i]>='a'&&str2[i]<='z'){
            str2[i]=str2[i]*2-63;
        }
        else{
            str2[i]*=2;
        }
    }
/*
    int min=(len1<len2)?len1:len2;
    for(int i=0;i<min;i++){
        int res=str1[i]-str2[i];
        if(res!=0) return res;
    }
    return len1-len2;
    */
    return strcmp(str1,str2);
}