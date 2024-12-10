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
// void delete_list(Node )
int main(){
    while(1){
        int n;
        cin>>n;
        int a[n];
        int status=true;
        foe(i,0,n-1) cin>>a[i];
        if(getchar()==EOF) status=false;
        Node root=creat_list(a,n);
        root=root->next;
        while(1){
            cout<<root->val;
            if(root->next!=NULL) cout<<' ';
            if(root->next==NULL) break;
            root=root->next;
        }
        cout<<endl;
        if(!status) return 0;
    }
}