#include<stdio.h>
void FindMax(int p[][3],int m,int n,int* pRow,int* pCol){
    //int i,j,t=p[0][0],a,b;
    int i,j,t=p[0][0],a=0,b=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(p[i][j]>t){
                t=p[i][j];
                a=i;
                b=j;
            }
        }
    }
    //pRow=&a,pCol=&b;
    *pRow=a,*pCol=b;
}
int main(){
    int a[2][3];
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    //int *pRow,*pCol;
    int pRow,pCol;
    //FindMax(a,2,3,pRow,pCol);
    FindMax(a,2,3,&pRow,&pCol);
    //printf("%d %d %d",a[*pRow][*pCol],*pRow,*pCol);
    printf("%d %d %d",a[pRow][pCol],pRow,pCol);

    return 0;
}