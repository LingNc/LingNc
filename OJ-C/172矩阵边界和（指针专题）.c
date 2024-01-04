#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    /*
    int *a=(int*)malloc(m*n*sizeof(int));
    memset(a,0,sizeof(int));
    int **a=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<=m-1;i++){
        *(a+i)=*
    }
    */
    /*
    int **p=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<=m-1;i++){
        *(p+i)=(int*)malloc(n*sizeof(int));
    }
    */
    //int p[m][n];
    //memset(p,0,sizeof(int));
    /*
    int **p=NULL;
    *p=(int*)malloc(m*n*sizeof(int));
    p=*p;
    for(int i=0;i<=n-1;i++){
        *(p+i)=*p+i;
    }
    */
    for(int j=0;j<=m-1;j++){
        for(int i=0;i<=n-1;i++){
            scanf("%d",&p[j][i]);
        }
    }
    for(int j=0;j<=m-1;j++){
        for(int i=0;i<=n-1;i++){
            printf("%d ",p[j][i]);
        }
        putchar('\n');
    }
    int *ptr=&p[0][0];
    for(int i=0;i<=m*n-1;i++){
        printf("%d ",*(ptr+i));
    }
    return 0;
}
int Sline(int* p,int m,int n,int* now){
    
    return 0;
}
//p[i]=*(p+i)
//p[i][j]=(p[i])[j]=*(p[i]+j)=*(*(p+i)+j)
//p[i]=*(p+i) &p[i]=p+i &*(p+i)=p+i
//&p[i][j]=&((p[i])[j])=&*(*(p+i)+j)=*(p+i)+j