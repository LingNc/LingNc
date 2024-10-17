#include<iostream>
using namespace std;
int func(int a,int b,int c){
    int number[10]={0,0,0,0,0,0,0,0,0,0}; // 数组大小应为10，而不是9
    int a_1=a%10,a_2=a/10%10,a_3=a/100;
    int b_1=b%10,b_2=b/10%10,b_3=b/100;
    int c_1=c%10,c_2=c/10%10,c_3=c/100;

    if(a_1 == 0 || a_2 == 0 || a_3 == 0 || b_1 == 0 || b_2 == 0 || b_3 == 0 || c_1 == 0 || c_2 == 0 || c_3 == 0) return 0;

    number[a_1]++;
    number[a_2]++;
    number[a_3]++;
    number[b_1]++;
    number[b_2]++;
    number[b_3]++;
    number[c_1]++;
    number[c_2]++;
    number[c_3]++;

    for(int i=1; i<10; i++) { // 应从1开始检查到9，而不是从0开始
        if(number[i]==0||number[i]>1) return 0;
    }
    return 1;
}
int main(){
    int a,b,c,f=0;
    cin>>a>>b>>c;
    for(int i=100;i<1000;i++){
        if(i%a==0){
            int j=i/a*b;
            int k=i/a*c;
            if(j<1000&&k<1000&&func(i,j,k)){
                cout<<i<<" "<<j<<" "<<k<<endl;
                f=1;
            }
        }
    }
    if(f==0) cout<<"no!!!"<<endl;
    return 0;
}