#include<stdio.h>
#include<string.h>
int main(){
    char a[]="abcdef";char b[]="xyz";
    strcpy(a,b);
    printf("%c",a[2]);
    return 0;
}