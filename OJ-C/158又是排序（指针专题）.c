#include<stdio.h>
void psort(int* pa,int* pb,int* pc,int* pd);
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int *pa=&a,*pb=&b,*pc=&c,*pd=&d;
    psort(pa,pb,pc,pd);
    printf("%d %d %d %d",*pa,*pb,*pc,*pd);
    return 0;
}
void psort(int* pa,int* pb,int* pc,int* pd){
    //实现四个数的排序，并分别放到四个指针所指向的变量里。
    int *p[4]={pa,pb,pc,pd};
    for(int j=0;j<=2;j++){
        for(int i=0;i<=2;i++){
            if(*p[i]<*p[i+1]){
                int t=*p[i];
                *p[i]=*p[i+1];
                *p[i+1]=t;
            }
        }
    }
}

