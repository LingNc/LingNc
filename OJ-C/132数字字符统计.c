#include<stdio.h>
#include<string.h>
int num_number(char a[],int num);
int main(){
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        char word[1000];
        gets(word);
        int n=strlen(word);
        printf("%d\n",num_number(word,n));
    }
    return 0;
}
int num_number(char a[],int n){
    int num=0;
    for(int i=0;i<=n-1;i++)
        if(a[i]>='0'&&a[i]<='9')
            num++;
    return num;
}