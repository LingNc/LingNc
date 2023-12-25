#include<stdio.h>
#include<limits.h>
void FindMax(int p[][3],int m,int n,int* pRow,int* pCol);
int main(){
    int p[2][3]={0};
    int *ptr=&p[0][0];
    for(int i=0;i<=5;i++){
        scanf("%d",&ptr[i]);
    }
    int pRow,pCol;
    FindMax(p,2,3,&pRow,&pCol);
    printf("%d %d %d",p[pRow][pCol],pRow,pCol);
    return 0;
}
void FindMax(int p[][3],int m,int n,int* pRow,int* pCol){
    //在m*n矩阵p中查找最大值，将其行下标存入pRow所指内存单元，将其列下标存入pCol所指内存单元
    int max=INT_MIN;
    for(int j=0;j<=m-1;j++){
        for(int i=0;i<=n-1;i++){
            if(p[j][i]>max){
                max=p[j][i];
                *pRow=j;
                *pCol=i;
            }
        }
    }
}