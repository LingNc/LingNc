#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#define endl '\n'
#define foe(i,a,b) for(auto i=(a);i<=(b);i++)
using namespace std;
void file_is_open(fstream &f){
    if(f) cout<<"文件打开成功"<<endl;
    else{
        cout<<"文件打开失败"<<endl;
        exit(1);
    }
}
typedef struct Book{
    string id,name,pub;
    bool status;
}Book;
int main(){
    fstream in("in.txt",ios::in),out("out.txt",ios::out);
    file_is_open(in),file_is_open(out);
    int n;
    in>>n;
    string id,name,pub;
    Book lis[n];
    foe(i,1,n){
        auto &it=lis[i-1];
        in>>it.id>>it.name>>it.pub>>it.status;
    }
    in>>name;
    out<<n<<endl;
    for(auto &it:lis){
        if(it.name==name){
            it.status=false;
        }
        out<<it.id<<' '<<it.name<<' '<<it.pub<<' '<<it.status<<endl;
    }
    in.close();out.close();
    return 0;
}