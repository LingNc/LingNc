#include<stdio.h>
int n;

struct Location{
    int x;
    int y;
    int num_x;
    int num_y;
};

int check(int a[][n],int n,struct Location *loc);

int main(){
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<=n-1;i++)
        for(int j=0;j<=n-1;j++)
            scanf("%d",&a[i][j]);
    struct Location loc={0};
    if(check(a,n,&loc))
        printf("OK");
    else{
        if(loc.num_x==1&&loc.num_y==1)
            printf("Change bit(%d,%d)",loc.y,loc.x);
        else
            printf("Corrupt");
    }
    return 0;
}
int check(int a[][n],int n,struct Location *loc){
    int flag=0;
    for(int i=0;i<=n-1;i++){
        int sum=0;
        for(int j=0;j<=n-1;j++)
            sum+=a[i][j];
        if(sum%2==0)
            flag++;
        else{
            loc->y=i;
            loc->num_y++;
        }
    }
    for(int j=0;j<=n-1;j++){
        int sum=0;
        for(int i=0;i<=n-1;i++)
            sum+=a[i][j];
        if(sum%2==0)
            flag++;
        else{
            loc->x=j;
            loc->num_x++;
        }
    }
    if(flag==2*n)
        return 1;
    else
        return 0;
}
