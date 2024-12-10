#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define string char
#define endl '\n'
using namespace std;

typedef struct node{
    string sign[100],name[100];
    double price;
    node *next;
    node(){}

}*Node,**LNode;

Node new_node(){
    Node temp=new node;
    cin>>temp->sign>>temp->name>>temp->price;
    temp->next=NULL;
    return temp;
}
void print_node(Node nnode){
    printf("%s %s %.2lf\n",nnode->sign,nnode->name,nnode->price);
}
inline int cout_list(Node root){
    Node head=root;
    int couts=0;
    while(1){
        couts++;
        if(!root->next) break;
        root=root->next;
    }
    return couts;
}

Node creat_list(int n){
    Node root=new node;
    Node tail=root;
    foe(i,1,n){
        Node temp=new_node();
        if(temp==NULL) break;

        tail->next=temp;

        tail=tail->next;
    }
    return root;
}
void print_list(Node root){
    root=root->next;
    while(1){
        print_node(root);
        if(root->next==NULL) break;
        root=root->next;
    }
}
double get_max_price(Node root){
    Node head=root->next;
    int i=1;
    double max_price=-1;
    while(1){
        if(head->price>max_price){
            max_price=head->price;
        }
        if(head->next==NULL) break;
        i++;
        head=head->next;
    }
    return max_price;
}
// 节点查找返回序号，找不到返回根节点的序号
int find_node(Node root,double max_price){
    Node head=root->next;
    int i=1;
    while(1){
        if(head->price==max_price) return i;
        if(head->next==NULL) return 0;
        i++;
        head=head->next;
    }
}
// 从序号找节点,找不到返回空指针NULL
Node get_node(Node root,int num){
    Node head=root;
    int i=0;
    while(1){
        if(i==num) return head;
        if(head->next==NULL) return NULL;
        head=head->next;
        i++;
    }
}

void del_list(Node root){
    Node p=root;
    while(p->next!=NULL){
        if(root->next!=NULL) root=root->next;
        delete p;
        p=root;
    }
}
// 删除序号n节点，返回true删除成功
bool del_node(Node root,int num){
    if(num==0)
        return false;
    Node now=get_node(root,num-1);
    if(now->next==NULL)
        return false;
    now->next=now->next->next;
    return true;
}
void solve(){
    int n;
    cin>>n;
    string sign[100],name[100];
    double price;
    Node root=creat_list(n);
    Node it=root;
    double max_price=get_max_price(root);
    while(true){
        int num=find_node(it,max_price);
        if(!num) break;
        it=get_node(it,num);
        print_node(it);
        if(it->next==NULL) break;
    }
}

int main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
