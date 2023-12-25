#include<stdio.h>
#include<string.h>
void insert_max(char str[],int n,int k);
int max_arr(char str[],int n);

int main(){
    char str[1200];
    int num[128];
    gets(str);
    int n=strlen(str);
    int max_i=max_arr(str,n);
    for(int i=0;i<=n-1;i++){
        if(str[i]==max_i){
            insert_max(str,n,i+1);
            n+=5;
            i+=4;
        }
    }
    puts(str);
    return 0;
}
void insert_max(char str[],int n,int k){
    char arr[1200];
    for(int i=n;i>=k;i--)
        arr[i-k]=str[i];
    str[k]='\0';
    strcat(str,"(max)");
    strcat(str,arr);
}
int max_arr(char str[],int n){
    int num[128]={0};
    for(int i=0;i<=n-1;i++)
        num[str[i]]++;
    for(int i=127;i>=0;i--)
        if(num[i]!=0)
            return i;
}