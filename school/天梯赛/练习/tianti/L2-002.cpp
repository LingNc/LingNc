#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long
typedef pair<int,int> PII;
#define all(a) a.begin(),a.end()

const int N=1e5+10;

struct Node{
    int addr,val,next;
}nodes[N];

void solve(){
    int head,n;
    cin>>head>>n;
    int addr,val,next;
    foe(i,0,n){
        cin>>addr>>val>>next;
        nodes[addr].addr=addr;
        nodes[addr].val=val;
        nodes[addr].next=next;
    }
    vector<Node> list1,list2;
    unordered_map<int,bool> seen;
    for(int p=head;p!=-1;p=nodes[p].next){
        int val=nodes[p].val;
        if(!seen.count(abs(val))){
            seen[abs(val)]=true;
            list1.push_back(nodes[p]);
        }
        else{
            list2.push_back(nodes[p]);
        }
    }
    foe(i,0,list1.size()){
        if(i!=list1.size()-1){
            list1[i].next=list1[i+1].addr;
        }
        else{
            list1[i].next=-1;
        }
    }
    foe(i,0,list2.size()){
        if(i!=list2.size()-1){
            list2[i].next=list2[i+1].addr;
        }
        else{
            list2[i].next=-1;
        }
    }
    for(auto &it:list1){
        // cout<<it.addr<<' '<<it.val<<' '<<it.next<<endl;
        if(it.next!=-1) printf("%05lld %lld %05lld\n",it.addr,it.val,it.next);
        else printf("%05lld %lld -1\n",it.addr,it.val);
    }
    for(auto &it:list2){
        // cout<<it.addr<<' '<<it.val<<' '<<it.next<<endl;
        if(it.next!=-1)printf("%05lld %lld %05lld\n",it.addr,it.val,it.next);
        else printf("%05lld %lld -1\n",it.addr,it.val);
    }
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}