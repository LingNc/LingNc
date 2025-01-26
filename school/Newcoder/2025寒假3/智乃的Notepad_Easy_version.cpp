#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b){ return b==0?a:gcd(b,a%b); }
template<typename iii> iii lcm(iii a,iii b){ return a/gcd(a,b)*b; }
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define yes(res) cout<<((res)?"YES":"NO")<<'\n'
#define foe(i,a,b) for(int i=(a);i<(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define INF64 0x3f3f3f3f3f3f3f3f
#define INF32 0x3f3f3f3f
#define int long long
#define endl '\n'
using i32=signed;
using i64=long long;
using namespace std;
typedef vector<int> arr;
typedef pair<int,int> PII;

const i32 N=1e5+10;

struct TrieNode{
    map<char,TrieNode *> children;
    int sum_child_lengths=0;
    int max_child_length=0;
    bool is_end=false;
};

void buildTrie(TrieNode *root,const vector<string> &words){
    for(const string &word:words){
        TrieNode *node=root;
        for(char c:word){
            if(node->children.find(c)==node->children.end()){
                node->children[c]=new TrieNode();
            }
            node=node->children[c];
        }
        node->is_end=true;
    }
}

void postOrderTraversal(TrieNode *root){
    stack<TrieNode *> stack;
    stack.push(root);
    vector<TrieNode *> postOrder;

    while(!stack.empty()){
        TrieNode *node=stack.top();
        stack.pop();
        postOrder.push_back(node);

        for(auto it=node->children.rbegin(); it!=node->children.rend(); ++it){
            stack.push(it->second);
        }
    }

    for(auto it=postOrder.rbegin(); it!=postOrder.rend(); ++it){
        TrieNode *node=*it;
        if(node->children.empty()){
            node->sum_child_lengths=0;
            node->max_child_length=0;
            continue;
        }
        int sum_cl=0;
        int max_cl=0;
        for(auto &child:node->children){
            int cl=1+child.second->sum_child_lengths;
            sum_cl+=cl;
            max_cl=max(max_cl,cl);
        }
        node->sum_child_lengths=sum_cl;
        node->max_child_length=max_cl;
    }
}

int calculateBackspace(TrieNode *root){
    int total_back=0;
    stack<TrieNode *> stack;
    stack.push(root);

    while(!stack.empty()){
        TrieNode *node=stack.top();
        stack.pop();
        if(!node->children.empty()){
            total_back+=node->sum_child_lengths-node->max_child_length;
            for(auto &child:node->children){
                stack.push(child.second);
            }
        }
    }

    return total_back;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> words(n);
    foe(i,0,n) cin>>words[i];

    foe(i,0,m){
        int l,r;
        cin>>l>>r;
        vector<string> current_words(words.begin()+l-1,words.begin()+r);

        TrieNode *root=new TrieNode();
        buildTrie(root,current_words);

        postOrderTraversal(root);

        int total_input=root->sum_child_lengths;
        int total_back=calculateBackspace(root);

        cout<<total_input+total_back<<endl;

        stack<TrieNode *> cleanupStack;
        cleanupStack.push(root);
        while(!cleanupStack.empty()){
            TrieNode *node=cleanupStack.top();
            cleanupStack.pop();
            for(auto &child:node->children){
                cleanupStack.push(child.second);
            }
            delete node;
        }
    }
}

i32 main(){
    IOS;
    i32 T=1;
    // cin >> T;
    while(T--) solve();
    return 0;
}