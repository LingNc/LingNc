#include<stdio.h>

void pri(int *p,int i,int j);
int main(){
    int m=2,n=3;
    int arr[m][n];
    int *p=&arr[0][0];
    for(int i=0;i<=n*m-1;i++){
        p[i]=i+1;
    }
    pri(p,1,2);
    return 0;
}
void pri(int *p,int i,int j){
    int m=2,n=3;
    //定义不同的访问方式的(指向数组的指针)
    int (*arr)[m]=(int (*)[m])p;//arr[3][2] arr是一个指向数组的指针 赋值给了p(p已经是分配好的6的地址)
    int (*brr)[n]=(int (*)[n])p;//brr[2][3] brr是一个指向数组的指针 赋值给了p(p已经是分配好的6的地址)
    printf("%p\n",&arr[1]);//一样,因为arr指向一个长度为2的数组
    printf("%p\n",arr+1);
    printf("%p\n",&arr);//&arr指向一个总长度为2*3=6的二维数组,如果访问&arr+1就会访问到整个二维数组后面,不该访问的位置
    printf("%d\n",arr[1][0]);//3
    /*
    arr={1,2
         3,4
         5,6}
    */
    printf("%d\n",brr[1][0]);//4
    /*
    brr={1,2,3
         4,5,6}
    */
}