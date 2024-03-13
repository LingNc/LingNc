#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//构造链表
LinkList Create(){
    int num=0;
    LinkList head,p,tail;
    head=(LinkList)malloc(sizeof(LNode));
    head->next=NULL;
    tail=head;
    while(1){
        scanf("%d",&num);
        if(num==-1) break;
        p=(LinkList)malloc(sizeof(LNode));
        p->data=num;
        tail->next=p;
        tail=p;
    }
    tail->next=NULL;
    return head;
}
void print( LinkList L);
int insert_link ( LinkList L,int i,ElemType e);
 
int main()
{
    int position,insert_data;int flag;
    LinkList L = Create();
    scanf("%d",&position);
    scanf("%d",&insert_data);    
    flag=insert_link(L,position,insert_data);
    if(flag) 
    {
        print(L);
    }
    else 
    { 
        printf("Wrong Position for Insertion");
    }
    return 0;
}
void print(LinkList L)
{ 
    LinkList p;
    p=L->next;
    while (p)
    {
         printf("%d ", p->data);
         p =p->next;
    }
}
 
int insert_link(LinkList L,int i,ElemType e){
    if(i<=0) return 0;
    LinkList it=L;
    int now=0;
    while(1){
        if(now==i-1) break;
        it=it->next;
        now++;
        if(it==NULL) return 0;
    }
    LinkList p=(LinkList)malloc(sizeof(LNode));
    p->data=e;
    p->next=it->next;
    it->next=p;
    return 1;
}