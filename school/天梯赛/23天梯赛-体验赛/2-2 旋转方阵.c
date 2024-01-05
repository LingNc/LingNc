#include<stdio.h>
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        int f[21][21]={0};
        int h[21][21]={0};
        n/=2;
        for(int x=-n;x<=n;x++){
            for(int y=-n;y<=n;y++){
                int num=f[11+x][11+y];
                scanf("%d",&num);
                m=m%4;
                if(m==0)
                    h[11+x][11+y]=num;
                else if(m==1)
                    h[11+y][11-x]=num;
                else if(m==2)
                    h[11-x][11-y]=num;
                else
                    h[11-y][11+x]=num;
            }
        }
        for(int x=-n;x<=n;x++){
            for(int y=-n;y<=n;y++){
                printf("%d",h[11+x][11+y]);
                if(y<n) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}