#include<stdio.h>
#include<string.h>
#include<idea.h>

int have_symmetry(char *str);
int is_reserve(char *str);
int main(){
    start();
    char str[10001]={0};
    scanf("%s",str);
    if(have_symmetry(str)&&is_reserve(str))
        puts("Yes");
    else
        puts("No");
    end();
    return 0;
}
int is_reserve(char *str){
    char s1[10001]={0};
    strcpy(s1,str);
    int len=strlen(str);
    for(int i=0;i<=(len-1)/2;i++){
        char t=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]=t;
    }
    return (strcmp(s1,str)==0)?1:0;
}
int have_symmetry(char *str){
    int len=strlen(str);
    return (strspn(str,"AHIMOTUVWXY")==len)?1:0;
    
}