#include<stdio.h>
#include<string.h>
int main(){
    char num[50]={ 0 };
    scanf("%s",num);
    int len=strlen(num);
    int m=len%3;
    for(int i=0;i<=len-1;i++){
        if((i-m)%3==0&&i!=0)
            printf("%c",',');
        printf("%c",num[i]);
    }

    return 0;
}
