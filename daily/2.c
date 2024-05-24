#include<stdio.h>
#define foe(i,a,b) for(int i=a;i<=b;i++)
int main(){
    int a=300;
    char *p=(char *)&a;
    foe(i,0,3){
        printf("%d ",*(p+i));
    }
    char a[4]={44,1,0,0};
    
    return 0;
}