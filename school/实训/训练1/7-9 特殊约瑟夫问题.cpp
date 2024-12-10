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
int main(){
    int N,M,K;
    cin>>N>>M>>K;
    int a[N];
    foe(i,0,N-1) a[i]=i+1;
    int now=0,last=N;
    bool status=1;
    while(last){
        if(status){
            now-=M-1;
            while(now<0) now+=last;
            now%=last;
        }
        else{
            now--;
            now+=K-1;
            now%=last;
        }
        cout<<a[now]<<' ';
        // print_arr(a,last);
        earse(a,last,now);
        last--;
        // now%=last;
        status=!status;
    }
}