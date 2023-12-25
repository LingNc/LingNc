#include<stdio.h>
int main(){
    char A[2][3]={'\0'};
    char * p=&A[0][0];
    for(int i=0;i<=5;i++)
        *(p+i)=i+'0';
    printf("%c",A[0][5]);
    return 0;
}