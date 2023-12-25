#include<stdio.h>
int find(int* list,int len,int num);
int main(){
    long long int N,M;
    int Q;
    scanf("%lld %lld %d",&N,&M,&Q);
    long long int list[2][Q];
    long long int* l0=&list[0][0],*l1=&list[1][0];
    for(int i=0;i<=2*Q-1;i++){
        *(l0+i)=0;
    }
    int x=0,y=0;

    while(Q--){
        int flag,a;
        scanf("%d %d",&flag,&a);
        if(flag==1&&find(l0,x,a)!=1){
            list[0][x]=a;
            x++;
        }
        else if(find==0&&find(l1,y,a)!=1){
            list[1][y]=a;
            y++;
        }
    }
    long long int safe=N*M-(y*M+x*N-y*x);
    printf("%lld",safe);
    return 0;
}
int find(int* list,int len,int num){
    for(int i=0;i<=len-1;i++){
        if(list[i]==num)
            return 1;
    }
    return 0;
}