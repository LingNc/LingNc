#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define endl '\n'
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PII pair<int,int>
#define int long long

void solve(){
	int q;
	cin>>q;
	deque<int> pre,fix;
	int op;
	int temp;
	foe(i,0,q){
		cin>>op;
		if(op==1){
			cin>>temp;
			pre.push_front(temp);
			if(pre.size()-fix.size()>1){
				fix.push_front(pre.back());
				pre.pop_back();
			}
		}
		else if(op==2){
			cin>>temp;
			fix.push_back(temp);
			if(fix.size()-pre.size()>0){
				pre.push_back(fix.front());
				fix.pop_front();
			}
		}
		else{
			cout<<pre.back()<<endl;
			pre.pop_back();
			if(fix.size()-pre.size()>0){
				pre.push_back(fix.front());
				fix.pop_front();
			}
		}
	}
}

signed main(){
	IOS;
	int T=1;
//	cin>>T;
	while(T--) solve();
}
