#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int greater(char* s1,char* s2);
int cmp(const void* p1,const void* p2){
    return greater(*(char**)p1,*(char**)p2);
}
int main(){
    int n;
    scanf("%d",&n);
    char* ptr[n];
    memset(ptr,0,sizeof(ptr));
    char str[n][101];
    memset(str,0,sizeof(str));
    for(int i=0;i<=n-1;i++){
        ptr[i]=str[i];
        scanf("%s",ptr[i]);
        int len=strlen(ptr[i]);
            for(int j=0;j<=len-2;j++){
                if(*ptr[i]=='0') ptr[i]++;
                else break;
            }
    }
    qsort(ptr,n,sizeof(char*),cmp);
    for(int i=0;i<=n-1;i++){
        puts(ptr[i]);
    }
    return 0;
}
//若s1指向的整数大于s2指向的整数，返回一个正整数;
//若s1指向的整数小于s2指向的整数，返回负整数;
//若s1指向的整数等于s2指向的整数，返回0;
int greater(char* s1,char* s2){
    int l1=strlen(s1),l2=strlen(s2);
    if(l1!=l2)
        return (l1>l2)?1:-1;
    else
        return strcmp(s1,s2);
}