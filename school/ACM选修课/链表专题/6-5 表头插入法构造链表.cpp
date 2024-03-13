#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
}snode,*ptr;

ptr  creat( );//构造链表
void output(ptr p);//输出链表元素

int main()
{
    ptr head;
    head=creat();
    output(head);
    return 0;
}

//构造链表
ptr creat( ){
    int num;
    ptr head,p;
    head=(ptr)malloc(sizeof(snode));
    head->next=NULL;
    while(1){
        scanf("%d",&num);
        if(num==0) break;
        p=(ptr)malloc(sizeof(snode));
        p->data=num;

        p->next=head->next;
        head->next=p;
    }
    return head;
}
//输出链表元素
void output(ptr p){
    while(p->next!=NULL){
        p=p->next;
        printf("%d ",p->data);
    }
}