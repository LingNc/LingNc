#include <stdio.h>
int main(){
    int a[5] = {1,2,3,4,5}; // 定义一个数组
    char* p =(char*)&a[0];
    //一个int是4个字节,一个char是1个字节
    //把一个int看作char a[4],那么这里的a就是一整个int(同时也指char a[4]的首地址)
    //可以用char指针来访问int里面4个字节都存那些东西了
    *p=*p<<1;
    for(int i=0;i<=3;i++){
        printf("%d ",*(p+i));
    }
    /*
    printf("数组名a的值：%p\n", a); // 输出数组名a的值，也就是数组首元素的地址
    printf("数组首元素的地址：%p\n", &a[0]); // 输出数组首元素的地址，和数组名a的值相同
    printf("数组名a的地址：%p\n", &a); // 输出数组名a的地址，和数组名a的值相同，但含义不同
    printf("数组名a+1的值：%p\n", a+1); // 输出数组名a+1的值，也就是数组第二个元素的地址
    printf("数组名a+1的地址：%p\n", &a+1); // 输出数组名a+1的地址，也就是数组结束后的下一个地址
    printf("数组第一个元素的值：%d\n", a[0]); // 输出数组第一个元素的值，也就是1
    printf("数组第一个元素的值：%d\n", *a); // 输出数组第一个元素的值，也就是1，和a[0]等价
    printf("数组第二个元素的值：%d\n", a[1]); // 输出数组第二个元素的值，也就是2
    printf("数组第二个元素的值：%d\n", *(a+1)); // 输出数组第二个元素的值，也就是2，和a[1]等价
    */
    return 0;
}
//p[i]=*(p+i)
//p[i][j]=(p[i])[j]=*(p[i]+j)=*(*(p+i)+j)
//p[i]=*(p+i) &p[i]=p+i &*(p+i)=p+i
//&p[i][j]=&((p[i])[j])=&*(*(p+i)+j)=*(p+i)+j
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