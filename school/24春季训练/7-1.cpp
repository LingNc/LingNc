#include<cstdio>
#include<algorithm>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;

int main(){
    int a,b,c;
    char ch;
    scanf("%d%c%d",&a,&ch,&b);
    if(ch=='+') c=a+b;
    else if(ch=='-') c=a-b;
    else if(ch=='*') c=a*b;
    else{
        puts("error");
        return 0;
    }
    printf("%d\n",c);
    return 0;
}