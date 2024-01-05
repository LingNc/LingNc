#include <stdio.h>
int Zhe(int x);
int main()
{
    int a, b;

    scanf("%d", &a);
    b = Zhe(a);
    printf("%d", b);

    return 0;
}
int Zhe(int x){
    int result=0;
    if(x>=300)
        result=x-100;
    else if(x>=200)
        result=x-80;
    else
        result=x;
    return result;
}