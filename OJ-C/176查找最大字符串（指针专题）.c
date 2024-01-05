#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void find(char* name[],int n,int* p);
int main(){
    char *str[10000]={NULL};
    int i=0;
    while(1){
        str[i]=(char*)malloc(sizeof(char)*6);
        scanf("%s",str[i]);
        if(strcmp(str[i],"*****")==0)
            break;
        i++;
    }
    int p=0;
    find(str,i+1,&p);
    puts(str[p]);
    char (*m)[6]=(char (*)[6])str;
    printf("%c",m[0][0]);
    return 0;
}
//在包含n个字符串的二维字符数组name中，查找值最大的字符串，将其下标存入指针p所指内存单元
void find(char* name[],int n,int* p){
    *p=0;
    for(int i=1;i<=n-1;i++){
        if(strcmp(name[i],name[*p])>0){
            *p=i;
        }
    }
}
