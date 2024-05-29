#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<vector>
#include<map>
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define endl '\n'

using namespace std;


void solve(){
	int n;
	cin>>n;
	map<string,int> m;
	string color;
	foe(i,1,n){
		cin>>color;
		if(m.find(color)->second)
			m[color]++;
		else
			m[color]=0;
	}
	pair<string,int> max;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second>max.second)
			max=*it;
	}
	cout<<max.first<<endl;
}

int main(){
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

