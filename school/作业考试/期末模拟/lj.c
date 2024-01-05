#include <stdio.h>
#include <string.h>

int IsSymmetricString(char* s);
int main()
{
    char s[10001];
    while (scanf("%s", s) != EOF)
    {
        if (IsSymmetricString(s))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

int IsSymmetricString(char* s)
{
    int length = strlen(s);
    if (length % 2 == 0)
    {
        for (int i = 0, j = length - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return 0;
        }
        return 1;
    }
    else
    {
        int mid = length / 2;
        if (s[mid] == 'A' || s[mid] == 'H' || s[mid] == 'I' || s[mid] == 'M' || s[mid] == 'O' || s[mid] == 'T' || s[mid] == 'U' || s[mid] == 'V' || s[mid] == 'W' || s[mid] == 'X' || s[mid] == 'Y')
        {
            for(int i = 0; i < mid; i++)
            {
                if (s[i] != s[length - 1 - i])
                    return 0;
            }
            return 1;
        }
        else
            return 0;
    }
}
