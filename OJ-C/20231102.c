#include<stdio.h>
int main(){
    int a=1243524,b=756342;
    a^=b^=a^=b;
    printf("%d %d",a,b);
    return 0;
}
