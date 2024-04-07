#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
using namespace std;

int main(){
    vector<int> p(10);
    foe(i,0,9)
        p[i]=i;
    int *ptr1=&p[0],*ptr2=&p[4];
    cout<<ptr2-ptr1<<endl;
    
    return 0;
}