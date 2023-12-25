#include<stdio.h>
#include<string.h>

char* num_trans(char* a,int len_a,int n);
int max(int a,int b);
void ch_plus(char* p,char ch);
int main(){
    char a[10001]={0};
    int n=2;
    char* p[2];
    while(n--){
        scanf("%[^\n]%*c",a);
        int len_a=strlen(a);
        p[n]=num_trans(a,len_a,n);
    }
    if(strcmp(p[0],p[1])==0){
        puts(p[0]);
    }
    else{
        puts(p[1]);
        puts(p[0]);
    }
    return 0;
}

char s[2][10001]={0};
char* num_trans(char* a,int len_a,int n){
    //to num
    for(int i=0;i<=len_a-1;i++){
        a[i]-='0';
    }
    for(int i=1;i<len_a;i++){
        if(a[i]%2==a[i-1]%2){
            ch_plus(s[n],max(a[i],a[i-1])+'0');
        }
    }
    return s[n];
}
int max(int a,int b){
    return (a>b)?a:b;
}
void ch_plus(char* p,char ch){
    char list[1]={ch};
    strcat(p,list);
}