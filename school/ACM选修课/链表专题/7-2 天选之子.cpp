#include<iostream>
#include<algorithm>
#include<stdlib.h>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)

using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node,*List;

List creat(int n);
void del(List p);
int main(){
    int n;
    cin>>n;
    List L=creat(n);
    L=L->next;
    while(L->next!=L){
        int i=1;
        while(i<=5){
            L=L->next;
            i++;
        }
        del(L);
        L=L->next;
    }
    cout<<L->data;
    return 0;
}
List creat(int n){
    List head,p,tail;
    head=(List)malloc(sizeof(Node));
    tail=head;
    for(int i=1;i<=n;i++){
        p=(List)malloc(sizeof(Node));
        p->data=i;
        tail->next=p;
        tail=p;
    }
    tail->next=head->next;
    return head;
}
void del(List p){
    p->next=p->next->next;
}

