#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define foe(i,a,b) for(int i=a;i<=b;i++)

int main(){
    int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,300};
    //1
    int *p1=arr[0];
    printf("%d ",*p1);
    putchar('\n');
    //2
    int *p2=arr[1];
    printf("%d ",p1[4]);
    printf("%d ",p2[0]);
    printf("%d ",p2[-1]);
    putchar('\n');
    //3
    int *p3=&arr[0][0];
    printf("%d ",p3[0]);
    printf("%d ",p3[4]);
    putchar('\n');
    //4
    int (*p4)[4]=arr;
    printf("%d ",p4[0]);
    printf("%d ",p4[1][2]);
    printf("%d ",p4[1][-1]);
    printf("%d ",p4[1][5]);
    putchar('\n');
    //5
    int (*p5)[3]=(int (*)[3])arr;
    printf("%d ",p5[1][2]);
    putchar('\n');
    //6
    char *p6=(char *)&p5[3][2];
    for(int i=0;i<=3;i++){
        printf("%d ",p6[i]);
    }
    putchar('\n');
    //7
    char brr[4]={1,1,0,0};
    int res=*(int *)brr;
    printf("%d ",res);
    putchar('\n');

    //8
    int m=3,n=4;
    int **c0=(int **)malloc(m*sizeof(int *));
    for(int i=0;i<=m-1;i++){
        c0[i]=(int *)malloc(n*sizeof(int));
    }

    for(int i=0;i<=m-1;i++){
        free(c0[i]);
    }
    free(c0);
    // 二维数组c0和arr有什么区别
    
    //9
    int (*c1)[4]=(int (*)[4])malloc(3*4*sizeof(int));
    int (*c2)[3][4]=(int (*)[3][4])malloc(1*3*4*sizeof(int));
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));

    int *pc1=*c1;
    int *pc2=(*c2)[0];

    for(int i=1;i<=12;i++){
        pc1[i-1]=pc2[i-1]=i;
    }

    #define m (*c2)
    printf("%d ",c2[0][1][2]);
    printf("%d ",m[1][2]);
    printf("%d ",*(*(m+1)+2));
    
    free(c1);
    free(c2);

    //二维数组c1,c2和arr分别有什么区别
    //二维数组m和arr有什么区别

    // int a=300;
    // char *p=(char *)&a;
    // foe(i,0,3){
    //     printf("%d ",*(p+i));
    // }
    // char b[4]={1,1,0,0};
    // int num=*(int *)&b;
    // printf("%d ",num);

    return 0;
}