#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#define endl '\n'
#define foe(i,a,b) for(auto i=(a);i<=(b);i++)
using namespace std;
void yes(fstream &f){
    if(f) cout<<"文件打开成功"<<endl;
    else{
        cout<<"文件打开失败"<<endl;
        exit(0);
    }
}
int main(){
    fstream in("in.txt",ios::in);
    yes(in);
    int n;
    in>>n;
    double svg=0;
    foe(i,1,n){
        string name,sign;
        double score;
        in>>name>>sign>>score;
        svg+=score;
    }
    fstream out("out.txt",ios::out);
    yes(out);
    out<<fixed<<setprecision(2);
    out<<svg/n;
    return 0;
}