#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int m=2,n=3;


    //用动态分配实现二维数组
    char **str=(char**)calloc(m,sizeof(char*));
    str[0]=(char*)calloc(m*n,sizeof(char));
    for(int i=1;i<=m-1;i++){
        str[i]=str[0]+i*n;
    }
    //二维数组
    //char ptr[m][n];
    //memset(ptr,0,sizeof(ptr));

    //
    //char **arr=(char**)malloc(m*sizeof(char*));
    //for(int i=0;i<=m-1;i++){
    //    arr[i]=(char*)malloc(n*sizeof(char));
    //}
    /*
    char *p=&str[0][0];
    for(int i=0;i<=m*n-1;i++){
        scanf("%c",&p[i]);
    }
    */
    //(char (*)[n]);
    char *p=&str[0][0];
    for(int i=0;i<=n*m-1;i++){
        scanf("%c",p);
    }
    printf("%c",**(str+1));
    printf("%c",str[1][0]);
    return 0;
}