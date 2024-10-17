#include<stdio.h>

int main(){
    int a=2;
    int *p=&a;
    printf("%d",*p);
    {
        int i=1;
        p=&i;
        printf("%d\n",*p);
    }
        printf("%d\n%d",*p);
    return 0;
}
int 