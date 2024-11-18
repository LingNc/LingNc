#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n % (m + 1) == 0) {
        printf("ZCY\n");
    } else {
        printf("WY\n");
    }
    return 0;
}