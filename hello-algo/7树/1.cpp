#include<iostream>
#include<algorithm>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a,b,j,c,d) foe(i,a,b)foe(j,c,d)
#define endl '\n'
#include<vector>
using namespace std;
template<typename T> struct Node{
    struct T val;
    Node *left,*right;
    template<typename T> Node(T x):val(x),left(NULL),right(NULL){}
};

int main(){
    
    return 0;
}
Node* Creat(){
    Node* root=;
    
}
template<typename T> Node* new_node(T x){
    Node* node=new Node(x);
}