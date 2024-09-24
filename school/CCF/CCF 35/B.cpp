#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b) {return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b) { return a/gcd(a,b)*b;}
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
//#define int long long
#define endl '\n'
#define INF32 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

using namespace std;
using i32=signed;
using i64=long long;

typedef vector<int> arr;
typedef pair<int,int> PII;

const int N=0;
string str;
string ans;
unordered_map<int,string> res;
unordered_map<string,int> unres;
vector<char> rules(256,0),cc(256,0);
int bgin,ccle;

void solveres(){
	int k=0;
	string temp;
	while(1){
		k++;
		temp=res[k-1];
		for(auto &it:temp)
			it=rules[it];
		if(unres.count(temp)==0){
			unres[temp]=k;
			res[k]=temp;
		}
		else{
			bgin=unres[temp];
			ccle=k-bgin;
			break;
		}
	}
}
string& getres(int k){
	if(k<=bgin+ccle-1) return res[k];
	else return res[bgin+(k-bgin)%ccle];
}

//int next(int ch){
//	return rules[ch];
//}
//
//int circle(){
//	int times;
//	int max_t=-1;
//	foe(i,0,255){
//		char to=next(i);
//		times=0;
//		while(to!=i&&to!=next(to)){
//			to=next(to);
//			if(to==i&&next(i)!=i){
//				do{
//					times++;
//					cc[to]=1;
//					to=next(to);
//				}while(to!=i);
//			}
//		}
//		max_t=max(max_t,times);
//	}
//	return max_t;
//}
//int start(){
//	int t2;
//	int max_t=-1;
//	foe(i,0,255){
//		if(cc[i]) continue;
//		t2=0;
//		char to=i;
//		while(to!=next(to)&&cc[to]!=1){
//			t2++;
//			to=next(to);
//		}
//		max_t=max(max_t,t2);
//	}
//	return max_t;
//}

void solve(){
	getline(cin,str);
	str.erase(0,1);str.pop_back();
	int n;
	cin>>n;
	getchar();
	string temp;
	foe(i,0,255) rules[i]=i;
	foe(i,1,n){
		getline(cin,temp);
		temp.erase(0,1);temp.pop_back();
		rules[temp[0]]=temp[1];
	}
	int m,k;
	cin>>m;
	res[0]=str;
	unres[str]=0;
	solveres();
//	int ccle=circle(),bgin=start();
	
	foe(i,1,m){
		cin>>k;
		cout<<"#"<<getres(k)<<"#"<<endl;
//		cout<<bgin<<' '<<ccle<<endl;
//		for(auto &it:res){
//			cout<<it.first<<' '<<it.second<<endl;
//		}
	}
}
i32 main(){
	int T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}
