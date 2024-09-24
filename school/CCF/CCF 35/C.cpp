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

typedef struct block{
	int NN,MM,nn,mm;
	bool right,h_right,c_right;
	int eql_num;
	vector<string> con,before,after;
	
	// 放入解析
	void push(string &str){
		if(str[0]!='-'&&str[0]!='+'&&str[0]>='0'&&str[0]<='9'){
			str.insert(str.begin(),'=');
			eql_num++;
		}
		con.push_back(str);
		if(str[0]!='-'&&str[0]!='+'&&str[0]!='='){
			right=false;
		}
		
		foe(i,1,str.size()-1){
			if(str[i]>'9'||str[i]<'0')
				right=false;
		}
		
		if(eql_num==con.size()){
			c_right=false;
		}
		else{
			c_right=true;
		}
		
		//解析放入和之后的文件 
		// 5
		if(str[0]=='-'||str[0]=='=') 
			before.push_back(str);
		else if(str[0]=='+'||str[0]=='=') 
			after.push_back(str);
		
		

	}
	
	
	// 是否合法
	bool isright(){
		bool res= right&&c_right&&h_right;
		
		//3.6
		if(before.size()!=MM||after.size()!=mm){
			res=false;
		}
		return res;
		
		//4.1
		
	}
	
	// 构造
	block(string &head){
		h_right=false;
		if(head.substr(0,2)=="@@"&&head.substr(head.size()-2,2)=="@@"){
			head.erase(head.begin(),head.begin()+3);
			head.erase(head.end()-3,head.end());
			stringstream ssin;
			ssin<<head;
			char ch=ssin.get();
			if(ch=='-'){
				ssin>>NN;
				ch=ssin.get();
				if(ch==','){
					ssin>>MM;
					ssin.get();
					ch=ssin.get();
					if(ch=='+'){
						ssin>>nn;
						ch=ssin.get();
						if(ch==','){
							ssin>>mm;
							h_right=true;
						}
					}
				}
			}
		}
	}
}Block;

class file {
	vector<string> before;
	vector<Block> diff;
	
	//4.1
//	int eql(Block &temp){
//		int NN=temp.NN-1;
//		foe(i,0,temp.MM-1){
//			bool res=true;
//			NN+=i;
//			foe(j,NN,temp.MM){
//				if(before[j]!=temp.before[j-NN]){
//					res=false;
//					break;
//				}
//			}
//		}
//	}
public:
	void push_before(string& str){
		before.push_back(str);
	}
	
	void push_block(Block& blk){
		diff.push_back(blk);
	}
	
	bool isright(){
		bool res=true;
		foe(i,0,diff.size()-1){
			res=(res&&diff[i].isright());
			
			//4.1
			
			
			if(i==0) continue;
			//3.3
			if(diff[i].NN<diff[i-1].NN+diff[i-1].MM){
				res=false;
				break;
			}
			
			//4.1
			
		}
		
		
		return res;
	}
};

void solve(){
	int n;
	cin>>n;
	file File;
	string str;
	foe(i,1,n){
		cin>>str;
		File.push_before(str);
	}
	getchar();
	while(1){
		getline(cin,str);
		Block blk(str);
		while(1){
			getline(cin,str);
			blk.push(str);
		}
	}
}
i32 main(){
	int T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}
