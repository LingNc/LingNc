#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][n],b[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            b[i][j]=0;
        }
    }
    if(m==0){
        for(int i=0;i<n;i++){
            b[i][i]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<b[i][j]<<' ';
            }
            cout<<endl;
        }
        return 0;
    }
    while(m--){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    b[i][j]+=a[i][k]*a[k][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=b[i][j];
                b[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}