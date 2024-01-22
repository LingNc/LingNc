#include <stdio.h>
#include <ctype.h>
#define N 10000
int main()
{
    char a[N];
    int s = 0;
    double b;
    scanf("%[^\n]%*c",a);
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (isdigit(a[i]))
        {
            b = a[i] - '0';
            if ((int)b == b)
                s = s + b;
        }
    }
    printf("%d", s);
    return 0;
}
