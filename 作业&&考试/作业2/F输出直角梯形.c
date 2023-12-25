#include<stdio.h>
void  printTrapezoid(int rows,int cols);
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    printTrapezoid(m,n);
    return 0;
}
void  printTrapezoid(int rows,int cols){
    for(int i=rows;i>=1;i--){
        printf("%*c",i,0);
        for(int j=0;j<=cols-i;j++){
            printf("*");
        }
        printf("\n");
    }
}
