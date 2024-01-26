#include<iostream>
#include<algorithm>
#include<cstring>
#define endl '\n'
using namespace std;

int main(){
    int r;
    cin>>r;
    int arr[r+1][r+1];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<=r-1;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=r-1;i>=0;i--){
        for(int j=0;j<=r-1;j++){
            arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
        }
    }
    cout<<arr[0][0]<<endl;
    return 0;
}