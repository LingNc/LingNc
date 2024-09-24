#include<bits/stdc++.h>
template<typename iii> iii gcd(iii a,iii b) {return b==0?a:gcd(b,a%b);}
template<typename iii> iii lcm(iii a,iii b) { return a/gcd(a,b)*b;}
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) a.begin(),a.end()
#define int long long
#define endl '\n'
#define INF32 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

using namespace std;
using i32=signed;
using i64=long long;

typedef vector<int> arr;
typedef pair<int,int> PII;

const int N=0;


void solve(){
	string str;
	cin>>str;
	arr a(256,0);
	for(auto &it:str)
		a[it]++;
	int res=2;
	foe(i,0,255){
		if(a[i]>2){
			res--;
			break;
		}
	}
	int x=0,y=0,z=0;
	foe(i,'a','z')
		x+=a[i];
	foe(i,'A','Z')
		x+=a[i];
	foe(i,'0','9')
		y+=a[i];
	if(a['*']||a['#']) z++;
	if(x&&y&&z) cout<<res<<endl;
	else cout<<0<<endl;
}
i32 main(){
	int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
}
