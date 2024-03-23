#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;

int main(){
    int x[4]={0},low,h;
    cin>>x[0]>>x[1]>>x[2]>>x[3]>>low>>h;
    int num1=0,max=-1;
    int l[4]={0},H[4]={0},sum[4]={0};
    foe(i,0,3){
        if(x[i]<low){
            num1++;
            l[i]=1;
            sum[i]=1;
        }
        if(x[i]>max){
            max=x[i];
        }
    }
    int num2=0;
    foe(i,0,3){
        if(max-x[i]>h){
            num2++;
            H[i]=1;
            sum[i]=1;
        }
    }
    int num12=0,k;
    foe(i,0,3){
        if(sum[i]){
            num12++;
            k=i+1;
        }
    }
    if(num1>=2||num2>=2||num12>=2) cout<<"Warning: please check all the tires!"<<endl;
    else if(num12==1){
        cout<<"Warning: please check #"<<k<<'!'<<endl;
    }
    else puts("Normal");
    return 0;
}