#include<iostream>
#include <string.h>
using namespace std;

/* 请在这里填写答案 */
class ID{
    string id;
public:
    ID(char oldID[]){
        id=oldID;
    }
    void convert(){
        id.insert(6,"19");
        int val[]={ 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
        char m[]={ '1','0','X','9','8','7','6','5','4','3','2' };
        int sum=0;
        for(int i=0;i<17;i++){
            sum+=(id[i]-'0')*val[i];
        }
        id+=m[sum%11];
    }
    void print(){
        cout<<id<<endl;
    }
};

int main(){
    char oldID[15];
    cin>>oldID;
    ID myID(oldID);
    cout<<"ID No.：";
    myID.print();
    myID.convert();
    cout<<"New ID NO.：";
    myID.print();
    return 0;
}

