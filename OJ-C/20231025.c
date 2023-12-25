#include<stdio.h>
#include<string.h>
void del(char a[],int n,int i);
int main(){
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        char str[50];
        gets(str);
        int num=strlen(str);
        for(int i=0;i<=num-1;i++){
            if(str[i]==32){
                del(str,num,i);
                i--;
            }
        }
        puts(str);
    }
    return 0;
}
void del(char a[],int n,int i){
    for(int j=i;j<=n-2;j++)
        a[j]=a[j+1];
    a[n-1]=0;
}