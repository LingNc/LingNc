#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#define endl '\n'
#define foe(i,a,b) for(auto i=(a);i<=(b);i++)
using namespace std;
// void yes(fstream &f){
//     if(f) cout<<"文件打开成功"<<endl;
//     else{
//         cout<<"文件打开失败"<<endl;
//         exit(1);
//     }
// }
int main(){
    string line;
    while(getline(cin,line)){
        bool is_prev_space=false;
        for(char ch:line){
            if(isspace(ch)){
                if(!is_prev_space){
                    cout<<' ';
                    is_prev_space=true;
                }
            }
            else{
                cout<<ch;
                is_prev_space=false;
            }
        }
        cout<<endl;
    }
    return 0;
}