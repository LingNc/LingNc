#include<cstdio>
int L,n,m,i,w,l,r,mid,pos,ans,a[55555];
bool ok(int x){
    for(pos=w=0,i=1;i<=n;i++)
        if(a[i]-pos<x)
            w++;
        else
            pos=a[i];
    return w<=m;
}
int main(){
    for(scanf("%d%d%d",&L,&n,&m),i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[++n]=L;
    for(l=1,r=L;l<=r;)
        if(ok(mid=l+r>>1))
            ans=mid,l=mid+1;
        else
            r=mid-1;
    printf("%d",ans);
}
