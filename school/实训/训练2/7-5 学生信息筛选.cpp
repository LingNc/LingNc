#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#define endl '\n'
#define foe(i,a,b) for(auto i=(a);i<=(b);i++)
using fstream=std::fstream;
using string=std::string;
void file_is_open(fstream&f){
    if(f) std::cout<<"文件打开成功"<<endl;
    else{
        std::cout<<"文件打开失败"<<endl;
        exit(1);
    }
}

int main(){
    fstream cin("stu1.txt",std::ios::in),cout("stu2.txt",std::ios::out);
    file_is_open(cin),file_is_open(cout);
    int n;
    cin>>n;
    string id,name;
    int num=0;
    std::vector<std::pair<string,string>> q;
    foe(i,1,n){
        cin>>id>>name;
        if(id.substr(0,2)=="54"){
            num++;
            q.push_back({ id,name });
        }
    }
    cout<<num<<endl;
    foe(i,1,num){
        auto &it=q[i-1];
        cout<<it.first<<' '<<it.second<<endl;
    }
    cin.close(),cout.close();
    return 0;
}