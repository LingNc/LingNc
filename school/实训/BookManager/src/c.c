#include<stdio.h>
#include<stdlib.h>
void *pm;
typedef struct Book{
    int a;
    int (*p)(Book *);
    Book *phis;
}Book;

int get_a(Book *pThis){
    return ((Book*)pm)->a;
}
typedef struct Stu{
    int b;
}Stu;

Book *init(Book *Bk,int a){
    Bk->a=a;
    Bk->p=get_a;
    Bk->phis=Bk;
}
Book *init(Stu *Bk,int b){

}


int main(){
    Book *n=(Book *)malloc(sizeof(Book));
    init(n,12);
    printf("%d\n",n->p(n));
    pm=n;
    printf("%d\n",((Book *)pm)->p((Book *)pm));
    return 0;
}