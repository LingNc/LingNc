#include  <stdio.h>
#define N 50
int SearchbyNum(long num[], int score[], int n,long number);

int main()
{  long  num[N],number;
   int  score[N],n,i,pos;
     
   scanf("%d", &n);
   for (i=0; i<n; i++)
      scanf("%ld:%d ", &num[i], &score[i]);
   scanf("%ld", &number);
     
   pos=SearchbyNum(num,score,n,number);
     
   if(pos==-1)
      printf("Not found!\n");
   else
      printf("%d\n",score[pos]);
            
   return 0;
}

int SearchbyNum(long num[], int score[], int n,long number){
    int pos=-1;
    for(int i=0;i<=n-1;i++){
        if(num[i]==number){
            pos=i;
            break;
        }
    }
    return pos;
}