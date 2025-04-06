#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
//#define endl '\n'
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using PII=pair<int,int>;
using i32=int;
#define int long long

PII qes(PII point){
	cout<<point.first<<point.second<<endl;
	cout.flush();
	PII res;
	cin>>res.first>>res.second;
	return res;
}

vector<vector<int>> mp(4,vector<int>(4,0));
vector<int> nums(9,0);

void ff(){
	int k=4;
	foe(i,1,4){
		int sum=0;
		foe(j,1,4){
			if(mp[i][j]==1){
				sum++;
			}
		}
		nums[k++]=sum;
	}
	k=1;
	foe(j,1,4){
		int sum=0;
		foe(i,1,4){
			if(mp[i][j]==1){
				sum++;
			}
		}
		nums[k++]=sum;
	}
	foe(i,1,4){
		if(mp[i][i]==1){
			nums[7]++;
		}
	}
	if(mp[1][3]==1){
		nums[8]++;
	}
	if(mp[2][2]==1){
		nums[8]++;
	}
	if(mp[3][1]==1){
		nums[8]++;
	}
}

void ff(PII point,int t){
	mp[point.first][point.second]=t;
	ff();
}

PII ffind(){
	int k=4;
	foe(i,1,4){
		int sum=0;
		foe(j,1,4){
			if(mp[i][j]==1){
				sum++;
			}				
		}
					if(sum==2){
				foe(m,1,4){
					if(mp[i][m]==0)
						return {i,m};
				}

			}
	}
	k=1;
	foe(j,1,4){
		int sum=0;
		foe(i,1,4){
			if(mp[i][j]==1){
				sum++;

			}

		}
		nums[k++]=sum;
					if(sum==2){
				foe(m,1,4){
					if(mp[j][m]==0){
						return {j,m};
					}
				}
			}
	}
	nums[7]=0;
	foe(i,1,4){
		if(mp[i][i]==1){
			nums[7]++;
		}
	}
	if(nums[7]==2){
		foe(i,1,4){
			if(mp[i][i]==0){
				return {i,i};
			}
		}
	}
	nums[8]=0;
	if(mp[1][3]==1){
		nums[8]++;
	}
	if(mp[2][2]==1){
		nums[8]++;
	}
	if(mp[3][1]==1){
		nums[8]++;
	}

	if(nums[8]==2){
		if(mp[1][3]==0){
			return {1,3};
		}
		if(mp[2][2]==0){
			return {2,2};
		}
		if(mp[3][1]==0){
			return {3,1};
	}
	}
}

void solve(){
	PII point;
	int x,y;
	cin>>x>>y;
	mp[x][y]=1;
	ff();
	if(x==2&&y==2){
		point.first=1,point.second=1;
		ff(point,2);
		point=qes(point);
		ff(point,1);
	}
	else{
		point.first=2,point.second=2;
		ff(point,2);
		point=qes(point);
		ff(point,1);
	}
	vector<PII> temp={{1,1},{1,3},{3,1},{3,3}};
	for(auto &it:temp){
		if(mp[it.first][it.second]==0){
			point=it;
			ff(point,2);
			point=qes(point);
			ff(point,1);
			break;
		}
	}
	while(true){
		foe(i,1,9){
			point=ffind();
			ff(point,2);
			point=qes(point);
			ff(point,1);
		}
	}
}

i32 main(){
	IOS;
	i32 T=1;
	// cin>>T;
	while(T--) solve();
}

