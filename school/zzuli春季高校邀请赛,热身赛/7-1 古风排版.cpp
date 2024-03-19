#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int main(){
    int N;
    cin>>N;
    getchar();
    char map[251][N];
    memset(map,0,sizeof(map));
    char ch;
    int k=0;
    foe(i,0,1001)
        foe(j,0,N-1){
        k=i;
        if(scanf("%c",&ch)==EOF||ch=='\n'){
            foe(k,j,N-1)
                map[i][k]=' ';
            goto end;
        }
        map[i][j]=ch;
    }
end:
    char map2[N][251];
    memset(map2,0,sizeof(map2));
    foe(j,0,N-1){
        for(int i=k;i>=0;i--){
            if()
                map2[j][i]=map[i][j];
        }
    }
    return 0;
}