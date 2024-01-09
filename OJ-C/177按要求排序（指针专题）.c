#include<stdio.h>
#include<stdlib.h>
void sort(int a[],int n,int (*cmp)(int,int));
int CmpAsc(int x,int y); /*按升序要求判断两元素是否逆序*/
int CmpDec(int x,int y); /*按降序要求判断两元素是否逆序*/
int CmpAbsAsc(int x,int y);  /*按绝对值升序要求判断两元素是否逆序*/
int main(void){
    int a[10],i,n;
    int slt;
    /*读入n和n个整数，存入数组a*/
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++){
        scanf("%d",&a[i]);
    }
    /*读入用户的选择，存入slt; */
    scanf("%d",&slt);

    switch(slt){
    case 1:   sort(a,n,CmpAsc); break;
    case 2:   sort(a,n,CmpDec); break;
    case 3:   sort(a,n,CmpAbsAsc);break;
    }

    /*输出排序后的数组*/
    for(int i=0;i<=n-1;i++){
        printf("%d ",a[i]);
    }

}
/*对数组a排序，排序原则由cmp指定，若cmp为真，表示两元素逆序*/
void sort(int a[],int n,int (*cmp)(int,int)){
    for(int i=0;i<=n-2;i++){
        for(int j=0;j<=n-2;j++){
            if(cmp(a[j],a[j+1])){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

}
//如果x>y返回1，否则返回0；
int CmpAsc(int x,int y){
    return (x>y)?1:0;
}
//如果x<y返回1，否则返回0；
int CmpDec(int x,int y){
    return (x<y)?1:0;
}
//如果abs(x)>abs(y)返回1，否则返回0
int CmpAbsAsc(int x, int y){
    return (abs(x)>abs(y))?1:0;
}