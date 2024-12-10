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
    int val;
    node *next;
}node,*Node;

Node creat_list(int arr[],int n){
    Node root=new node;
    Node tail=root;
    foe(i,0,n-1){
        Node temp=new node;
        temp->val=arr[i];
        temp->next=NULL;

        tail->next=temp;
        tail=tail->next;
    }
    return root;
}
void print_list(Node root){
    root=root->next;
    while(1){
        cout<<root->val;
        if(root->next!=NULL) cout<<' ';
        if(root->next==NULL) break;
        root=root->next;
    }
    cout<<endl;
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
    int a[n];
    foe(i,0,n-1) cin>>a[i];
    Node tail=creat_list(a,n);
    Node A=tail;
    Node B=new node,C=new node;
    Node B_tail=B,C_tail=C;
    while(1){
        tail=tail->next;
        if(tail->val<=0){
            B_tail->next=tail;
            B_tail=B_tail->next;
        }
        else{
            C_tail->next=tail;
            C_tail=C_tail->next;
        }
        if(tail->next==NULL) break;
    }
    delete A;
    C_tail->next=NULL;
    B_tail->next=NULL;
    print_list(B);
    print_list(C);
}

int main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}