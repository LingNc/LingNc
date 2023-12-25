#include<stdio.h>
#include<string.h>
int min(int a,int b);
int compare_char(char ch1,char ch2);
int compare_str(char* str1,char* str2);
int main(){
    char str1[10001]={0},str2[10001]={0};
    while(scanf("%[^\n]%*c",str1)!=EOF&&scanf("%[^\n]%*c",str2)!=EOF){
        char* result[]={"Yes","No","No"};
        printf("%s\n",result[1+compare_str(str1,str2)]);
    }
    return 0;
}
int compare_char(char ch1,char ch2){
    double a=(ch1>='a'&&ch1<='z')?ch1-'a'+'A'+0.5:ch1;
    double b=(ch2>='a'&&ch2<='z')?ch2-'a'+'A'+0.5:ch2;
    return (a==b)?0:((a>b)?1:-1);
}
int compare_str(char* str1,char* str2){
    int i=0;
    int n=min(strlen(str1),strlen(str2));
    while(1){
        int flag=compare_char(*(str1+i),*(str2+i));
        if(flag==0){
            i++;
            continue;
        }
        else{
            return flag;
        }

    }
}
int min(int a,int b){
    return (a<b)?a:b;
}