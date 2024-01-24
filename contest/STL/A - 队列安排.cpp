#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    vector<int> stu{ 1 };
    int N;
    cin>>N;
    int k,p,ns=1;
    vector<int>::iterator it;
    for(int i=2;i<=N;i++){
        cin>>k>>p;
        ns++;
        it=find(stu.begin(),stu.end(),k);
        if(p) it++;
        stu.emplace(it,ns);
    }
    int M;
    cin>>M;
    for(int i=1;i<=M;i++){
        cin>>ns;
        it=find(stu.begin(),stu.end(),ns);
        if(it!=stu.end())
            stu.erase(it);
    }
    for(int i=0;i<=stu.size()-1;i++){
        cout<<stu[i]<<' ';
    }
    return 0;
}