# include <iostream>
# include <algorithm>
using namespace std;
int n,c;
const int N = 1e5+10;
int a[N];

bool check(int st){
	int pre = a[0];
	int sum = 1;
	for(int i=1;i<n;++i){
		if(a[i]-pre >= st){
			++sum;
			pre = a[i];
			if(sum>=c) return true;
		}
	}
	return false;
}
int main(void)
{
	cin>>n>>c;
	for(int i=0;i<n;++i){
		cin>>a[i];
	} 
	
	sort(a,a+n);
	
	int l = 0,r = a[n-1] - a[0];
	int ans = 0;
	
	while(l<r){
		int mid = (l+r +1 ) >> 1 ;
		if(check(mid)){
			l = mid;
		}else{
			r = mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
 } 
