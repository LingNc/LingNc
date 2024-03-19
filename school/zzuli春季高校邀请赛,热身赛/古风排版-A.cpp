#include<stdio.h>
#include<string.h>
int main(){
    char a[101][101],ch;
    int i,j,n,h,l;
    scanf("%d",&n);//n为每列的字符数
    getchar();
    h=0;l=0;//h为行，l为列
    while((ch=getchar())!='\n'){
        h+=l/n;//当一列满n时行数的字符数加一
        l%=n;//每列的字符数从一到n循环
        a[h][l++]=ch;//将字符存储到二维数组中
    }
    //逆置输出字符
    for(i=0;i<n;i++){  //控制二维数组的行数
        for(j=h;j>=0;j--){//控制二维数组每行的字符数
            putchar(a[j][i]?a[j][i]:' ');
        }
        putchar('\n');
    }
}