#include<iostream>
#include<algorithm>
#include<string>
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define endl '\n'

using namespace std;

int main(){
	string str;
	cin>>str;
	if(str=="gold")
		cout<<"Au"<<endl;
	else if(str=="silver")
		cout<<"Ag"<<endl;
	else
		cout<<"Cu"<<endl;
	return 0;
}
