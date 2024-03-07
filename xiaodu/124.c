#include<stdio.h>
void PrintArr(int a[],int n);
void sort(int a[],int n);
int main(){
    int n,m,i,x=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int b[m];
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    int c[m+n];
    for(i=0;i<n;i++){
        c[i]=a[i];
    }
    for(i=n;i<m+n;i++){
        c[i]=b[x];
        x++;
    }
    sort(c,m+n);
    PrintArr(c,m+n);

    return 0;
}
void PrintArr(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
void sort(int a[],int n){
    int i,c,x=n;
    while(x>0){
        x--;
        for(i=0;i<n-1;i++){
            if(a[i]<a[i+1]){
                c=a[i+1];
                a[i+1]=a[i];
                a[i]=c;
            }
        }
    }
}
