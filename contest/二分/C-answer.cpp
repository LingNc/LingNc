#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <stdlib.h>
#include <list>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <vector>
#define pi acos(-1.0)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int min3(int a,int b,int c){ return min(min(a,b),c); }
int max3(int a,int b,int c){ return max(max(a,b),c); }
int gcd(int x,int y){ if(y==0)return x;return gcd(y,x%y); }
inline int read(){ int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar(); }while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();return x*f; }
double a,b,c,d;
double fc(double x){
    return a*x*x*x+b*x*x+c*x+d;
}
int main(){
    double l,r,m,y1,y2;
    int cnt=0;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);

    for(int i=-100;i<=100;i++){
        l=i;
        r=i+1;
        y1=fc(l);
        y2=fc(r);
        if(!y1){
            printf("%.2lf ",l);
            cnt++;
        }//判断左端点，是零点直接输出。
        //不能判断右端点，会重复。

        if(y1*y2<0){
            while(r-l>=0.001){
                m=(l+r)/2;
                if(fc(m)*fc(r)<0)
                    l=m;
                else
                    r=m;
            }
            printf("%.2lf ",r);
            cnt++;
        }
        if(cnt==3)
            break;//找到三个就退出大概会省一点时间
    }
    printf("\n");

    return 0;
}