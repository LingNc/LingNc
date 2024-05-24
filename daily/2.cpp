#include<iostream>
#include<algorithm>
#include<string>
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define endl '\n'

using namespace std;
int main(){
	int a=257;
	int *ptr=&a;
	char *p=(char *)ptr;
	foe(i,0,3){
		cout<<*(p+i)<<endl;
	}
	return 0;
}
