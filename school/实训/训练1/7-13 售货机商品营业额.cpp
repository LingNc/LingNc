#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
// #define endl '\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define string char
using namespace std;
void Swap(string*x,string*y){
    auto t=*x;
    *x=*y;
    *y=t;
}
string *reverse(string *begin){
    int len=strlen(begin)-1;
    foe(i,0,len/2)
        Swap(begin+i,begin+len-i);
    return begin;
}
size_t find(string str[],char ch){
    size_t len=strlen(str);
    if(len==0) return 0;
    foe(i,0,len-1) if(str[i]==ch) return i;
    return len;
}
string *earse(string str[],size_t pos){
    size_t len=strlen(str);
    if(len==0) return str;
    foe(i,pos,len-1)
        str[i]=str[i+1];
    return str;
}
string *earse(string str[],char ch){
    size_t len=strlen(str);
    if(len==0) return str;
    while(1){
        auto res=find(str,ch);
        if(res==len) break;
        earse(str,res);
        len--;
    }
    return str;
}
int *earse(int arr[],int n,int pos){
    foe(i,pos,n-2){
        arr[i]=arr[i+1];
    }
    return arr;
}
void print_arr(int a[],int n){
    foe(i,0,n-1)
        cout<<a[i]<<' ';
    cout<<endl;
}
typedef struct node{
    string name[100];
    int num;
    double price;
    node *next;
}node,*Node;

Node new_node(){
    Node temp=new node;
    string name[100];
    int num;
    double price;
    cin>>name>>num>>price;
    strcpy(temp->name,name);
    temp->num=num;
    temp->price=price;
    return temp;
}
inline Node cout_node(Node root){
    // cout<<root->name<<;
}
Node creat_list(int n){
    Node root=new node;
    Node tail=root;
    foe(i,0,n-1){
        Node temp=new_node();
        temp->next=NULL;

        tail->next=temp;
        tail=tail->next;
    }
    return root;
}
void print_list(Node root){
    root=root->next;
    while(1){
        cout_node(root);
        if(root->next==NULL) break;
        root=root->next;
    }
    cout<<endl;
}
// 节点查找返回序号，找不到返回根节点的序号
int find_node(Node root,string name[]){
    Node head=root->next;
    int i=1;
    while(1){
        if(strcmp(head->name,name)==0) return i;
        if(head->next==NULL) return 0;
        i++;
        head=head->next;
    }
}
// 从序号找节点,找不到返回空指针NULL
Node getNode(Node root,int num){
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
    Node now=getNode(root,num-1);
    if(now->next==NULL)
        return false;
    now->next=now->next->next;
    return true;
}
bool sell(Node root,Node node,int num){
    if(num>node->num)
        return false;
    else if(num==node->num)
        del_node(root,find_node(root,node->name));
    else
        node->num-=num;
    return true;
}
void solve(){
    int n;
    cin>>n;
    Node root=creat_list(n);
    int t;
    cin>>t;
    string name[100];
    int num;
    double sumPrice=0;
    bool status=true;
    foe(i,1,t){
        cin>>name>>num;
        auto indeo=find_node(root,name);
        if(!indeo){
            status=false;
            break;
        }
        auto anode=getNode(root,indeo);
        if(anode==NULL){
            status=false;
            break;
        }
        status=status&&sell(root,anode,num);
        if(!status) break;
        sumPrice+=anode->price*num;
    }
    del_list(root);
    if(status)
        printf("%.2lf\n",sumPrice);
    else
        cout<<"error"<<endl;
}

int main(){
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}