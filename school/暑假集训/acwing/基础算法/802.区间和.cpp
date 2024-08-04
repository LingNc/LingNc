#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()

using namespace std;
using i32=signed;
using i64=long long;

typedef pair<int,int> PII;
vector<PII> add,query;
//离散表存所有可能用到的数字
vector<int> alls;

//一个n是1e5 然后对应l和r分别都是1e5个一共需要3e5的离散化数组
const int N=3e5+10;
//前缀和 a差分数组 s前缀和数组
int a[N],s[N];

int find(int x){
    int l=0,r=alls.size()-1;
    while(l+1!=r){
        int mid=l+r>>1;
        if(alls[mid]<=x) l=mid;
        else r=mid;
    }
    return r;
}

void solve(){
    int n,m;
    cin>>n>>m;
    int x,c;
    cin>>x>>c;
    foe(i,1,n){
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    int l,r;
    foe(i,1,m){
        cin>>l>>r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }

    //离散化alls
    //排序
    sort(all(alls));
    //去重
    //unique() 把重复的放在后面返回最后一个不重复的位置的下一个
    alls.erase(unique(all(alls)),alls.end());

    //处理插入add
    for(auto &i:add){
        //找到离散数组中的对应的下标
        int x=find(i.first);
        // 加入原数组
        a[x]+=i.second;
    }
    //求原数组的前缀和,前缀和数组的0位置是0,
    foe(i,1,alls.size()-1)
        s[i]=s[i-1]+a[i];

    //q个询问
    for(auto &q:query){
        int l=find(q.first),r=find(q.second);
        cout<<s[r]-s[l-1]<<endl;
    }
}
i32 main(){
    IOS;
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}