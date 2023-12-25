#include <stdio.h>
int f(int n) {
  if (n == 1) {
    return 1; 
  }
  else {
    return 2 * (f(n - 1) + 1); 
  }
}

int main() {
  int n; 
  scanf("%d", &n); 
  printf("%d", f(n)); 
  return 0; 
}
