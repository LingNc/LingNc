#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define endl '\n'

using namespace std;

void solve(){
	int HH,MM;
	scanf("%d:%d",&HH,&MM);
	//cin>>HH>>MM;
	string Q;
	cin>>Q;
	if(Q!="7-1"){
		cout<<"05:05"<<endl;
	}
	else{
		MM+=5;
		if(MM>=60){
			HH++;
		}
		MM%=60;
		cout.fill('0');
		cout<<setw(2)<<HH<<':'<<setw(2)<<MM<<endl;
	}
}

int main(){
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

