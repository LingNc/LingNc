#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t;
	cin>>t;
	while(t--){
		long long a,b,c,d,e,f,x,y;
		cin>>a>>b>>c>>d;
		e=a-c;
		f=b-d;
		x=gcd(e,b);
		y=gcd(f,c);
		cout<<gcd(x,y)<<endl;
		
	}
}
