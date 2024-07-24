#include<bits/stdc++.h>
#define ll long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;
//行列式
int cal(vector<vector<int>> &det,int n);

void solve(){
    int n,m;
    cin>>n>>m;
    int md=max(n,m);
    vector<vector<int>> det(md,vector<int>(md,0));
    int min_res=INT_MAX;
    foe(i,0,n-1)
        foe(j,0,m-1)
            cin>>det[i][j];

    foe(i,1,md){
        min_res=min(min_res,cal(det,i));
    }
    cout<<min_res<<endl;
}

signed main(){
    IOS;
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
int cal(vector<vector<int>>& det,int n)//det-行列式，n:行列式的阶数
{
	int detVal = 0;//行列式的值
	
	if(n == 1)//递归终止条件 
	return det[0][0]; 
    vector<vector<int>> tempdet(n-1,vector<int>(n-1,0));
	for(int i=0;i<n;i++)//第一重循环，行列式按第一行展开 
	{
		for(int j=0;j<n-1;j++)
		for(int k=0;k<n-1;k++)
		{
			if(k <i)
			tempdet[j][k]=det[j+1][k] ;
			else
			tempdet[j][k]=det[j+1][k+1];
		}
		detVal += det[0][i] * pow(-1,i) * cal(tempdet,n-1);
	
	 } 
	 return detVal;
} 
