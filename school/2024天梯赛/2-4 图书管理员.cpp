#include<bits/stdc++.h>
#define endl '\n'
#define foe(i,a,b) for(auto i=(a);i<=(b);i++)
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;

typedef struct Book{
    string id,date;
    int nums;
}Book;

bool cmp1(const Book &a,const Book &b){
    return a.id<b.id;
}

bool cmp2(const Book &a,const Book &b){
    if(a.date==b.date){
        return a.id<b.id;
    }
    else return a.date<b.date;
}

bool cmp3(const Book &a,const Book &b){
    if(a.nums==b.nums) return a.id<b.id;
    else return a.nums<b.nums;
}

signed main(){
    int n;
    cin>>n;
    vector<vector<Book>> lis(3,vector<Book>(n,{ "","",0 }));
    foe(i,0,n-1){
        auto &it=lis[0][i];
        cin>>it.id>>it.date>>it.nums;
    }
    lis[2]=lis[1]=lis[0];
    stable_sort(all(lis[0]),cmp1);
    stable_sort(all(lis[1]),cmp2);
    stable_sort(all(lis[2]),cmp3);
    int m;
    cin>>m;
    int ques=0;
    foe(k,1,m){
        cin>>ques;
        auto &li=lis[ques-1];
        for(int i=0; i<=min((size_t)99,li.size()-1); i++){
            if(!i) cout<<li[i].id;
            else cout<<' '<<li[i].id;
        }
        cout<<endl;
    }
    return 0;
}