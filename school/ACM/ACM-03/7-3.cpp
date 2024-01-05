#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;
bool prime(int num);
int main(){
    int A,B;
    cin>>A>>B;
    bool flag=0;
    for(int i=A;i<=B;i++){
        if(prime(i)){
            if(flag==0){
                cout<<i; 
                flag=1;
            }
            else{
                cout<<','<<i;
            }
                   
        }

    }
    printf("\n");
    return 0;
}
bool prime(int num){
    if(num<=3) return (num<=1)?0:1;
    int sq=(int)sqrt(num);
    for(int i=2;i<=sq;i++)
        if(num%i==0) return 0;
    return 1;
}