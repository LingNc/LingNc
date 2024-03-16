#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int sum_num(int num);
bool is_heart(int num);

int main(){
    int N,num;
    cin>>N;
    while(N--){
        cin>>num;
        if(is_heart(num))
            cout<<sum_num(num)<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
bool is_heart(int num){
    int sum=sum_num(num*2);
    foe(i,3,9){
        if(sum_num(num*i)!=sum)
            return 0;
    }
    return 1;
}
int sum_num(int num){
    int sum=0;
    while(num){
        sum+=num%10;
        num/=10;
    }
    return sum;
}