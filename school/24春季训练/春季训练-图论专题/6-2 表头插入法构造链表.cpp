
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
ptr creat(){
    ptr root=(ptr)malloc(sizeof(snode));
    root->next=NULL;
    ptr head=root,p;

    while(1){
        int num;
        scanf("%d",&num);
        if(num==0) break;
        p=(ptr)malloc(sizeof(snode));
        p->data=num;

        p->next=head->next;
        head->next=p;
    }
    return root;
}
void output(ptr p){
    while(p->next!=NULL){
        printf("%d ",p->next->data);
        p=p->next;
    }
}
