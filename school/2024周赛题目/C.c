#include<stdio.h>
#include<math.h>
int a[1005][1005];
int main() {
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=n-2;i>=0;i--){
        for(j=0;j<=i;j++){
            a[i][j]+=fmax(a[i+1][j],a[i+1][j+1]);
        }
    }
    printf("%d",a[0][0]);
    return 0;
}