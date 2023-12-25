#include<iostream>
using namespace std;

void swap(int* a,int* b);
void swap_2(int& a,int& b);
int main(){
    int a=3,b=2;
    swap_2(a,b);
    cout<<a<<" "<<b;
    return 0;
}
void swap(int* a,int* b){
    int* temp=a;
    a=b;
    b=temp;
}
void swap_2(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}