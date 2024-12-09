#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#define endl '\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define string char
using namespace std;
void Swap(string *x,string *y){
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
    string name[10];
    int age;
    node *next;
}node,*Node;

Node creat_list(int n){
    Node root=new node;
    Node tail=root;
    foe(i,0,n-1){
        string name[11];
        int age;
        cin>>name>>age;
        Node temp=new node;
        strcpy(temp->name,name);
        temp->age=age;
        temp->next=NULL;

        tail->next=temp;
        tail=tail->next;
    }
    return root;
}
void reversePrint(Node root){
    if(root==nullptr) return;
    reversePrint(root->next);
    cout<<root->name<<' '<<root->age<<endl;
}
void del_list(Node root){
    Node p=root;
    while(p->next!=NULL){
        if(root->next!=NULL) root=root->next;
        delete p;
        p=root;
        if(p->next==NULL) delete p;
    }
}
void solve(){
    int n;
    cin>>n;
    Node root=creat_list(n);
    Node head=root->next;
    reversePrint(head);
}

int main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}