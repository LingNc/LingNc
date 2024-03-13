
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList Create ();/* 细节在此不表 */
void Traverse ( LinkList L );
int main()
{
    LinkList L = Create();
    Traverse(L);
    return 0;
}

void Traverse (LinkList L){
    while(L->next!=NULL){
        L=L->next;
        printf("%d ",L->data);
    }
}