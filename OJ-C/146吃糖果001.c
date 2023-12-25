#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int m;
        scanf("%d",&m);
        int candy[m];
        for(int j=0;j<=m-1;j++)
            scanf("%d",&candy[j]);
        
    }
    return 0;
}
int eat(int candy[],int last_k,int k){
    int n=sizeof(candy)/sizeof(int);
    int last_num=candy[last_k]+1;
    int min=0;
    for(int i=0;i<=n-1;i++){
        if(i!=last_k){
            if(last_num-)
        }
    }
}
int arr_max(int candy[],int last_k){
    int n=sizeof(candy)/sizeof(int);
    int last_num=candy[last_k];
    candy[last_k]=0;
    for(int i=0;i<=n-1;i++){
        if(i!=last_k){
            
        }
    }

}