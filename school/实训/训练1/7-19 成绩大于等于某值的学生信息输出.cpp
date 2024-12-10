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

struct stud_node{
    int id;
    char name[100];
    double score;
    stud_node *next;
};

typedef stud_node *Node,node;

Node new_node(){
    Node temp=new node;
    cin>>temp->id;
    if(temp->id==0) return NULL;
    cin>>temp->name>>temp->score;
    temp->next=NULL;
    return temp;
}
void print_node(Node nnode){
    cout<<nnode->id<<' '<<nnode->name<<' '<<nnode->score<<endl;
}
inline int cout_node(Node root){
    Node head=root;
    int couts=0;
    while(1){
        couts++;
        if(!root->next) break;
        root=root->next;
    }
    return couts;
}

Node creat_list(){
    Node root=new node;
    Node tail=root;
    while(1){
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
// 节点查找返回序号，找不到返回根节点的序号
int find_node(Node root,int min_score){
    Node head=root->next;
    int i=1;
    while(1){
        if(head->score<min_score) return i;
        if(head->next==NULL) return 0;
        i++;
        head=head->next;
    }
}
// 从序号找节点,找不到返回空指针NULL
Node get_node(Node root,int num){
    int i=0;
    while(1){
        if(i==num) return root;
        if(root->next==NULL) return NULL;
        root=root->next;
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
stud_node *Creat_Stu_Doc(){
    return creat_list();
}

stud_node *DeleteDoc(struct stud_node *head,int min_score){
    while(1){
        int inode=find_node(head,min_score);
        if(inode==0) break;
        del_node(head,inode);
    }
    return head;
}

void Print_Stu_Doc(struct stud_node *head){
    print_list(head);
}

void solve(){
    Node head=Creat_Stu_Doc();
    int min_score;
    cin>>min_score;
    head=DeleteDoc(head,min_score);
    Print_Stu_Doc(head);
}

int main(){
    int T=1;
    while(T--) solve();
    return 0;
}
