#include<stdio.h>
int main(){
    long long int N,M;
    int Q;
    scanf("%lld %lld %d",&N,&M,&Q);
    int x=0,y=0;
    int h[2][Q];
    int* p0=h[0],np0=0;
    int* p1=h[1],np1=0;
    while(Q--){
        int flag,num;
        scanf("%d %d",&flag,&num);
        if(flag==0){
            y++;
            *(p0++)=num;
            np0++;
        }
        else{
            x++;
            *(p1++)=num;
            np1++;
        }
    }
    for(int j=0;j<=1;j++){
        int np=(j==0)?np0:np1;
        for(int i=0;i<=np-2;i++){
            if(h[j][i]>h[j][i+1]){
                int t=h[j][i];
                h[j][i]=h[j][i+1];
                h[j][i+1]=t;
            }
        }
    }
    int lose_x=0,lose_y=0;
    for(int i=0;i<=1;i++){
        int np=(i==0)?np0:np1;
        for(int j=0;j<=np-2;j++){
            if(h[i][j]==h[i][j+1]){
                if(j==0)
                    lose_y++;
                else
                    lose_x++;
            }
        }
    }
    y-=lose_y;
    x-=lose_x;
    long long int safe=N*M-(y*M+x*N-y*x);
    printf("%lld",safe);
    return 0;
}