#include<iostream>
#include<algorithm>
#define ll long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

const int N=10;
int n;
char map[N][N];
bool row[N],col[N],dg[N],udg[N];
// 深度优先搜索函数，用于解决八皇后问题
// 参数:
// x, y: 当前放置皇后的列数和行数
// Q: 已放置的皇后数量
void dfs(int x, int y, int Q)
{
    // 当到达最后一列时，行数增加，列数重置为0，准备放置下一行的皇后
    if (x == n) 
        y++, x = 0;
    
    // 如果已经放置了n个皇后，解决方案找到
    if (y == n) {
        // 如果放置了n个皇后，打印解决方案
        if (Q == n) {
            for (int i = 0; i < n; i++) 
                puts(map[i]);
            cout << endl;
        }
        // 返回，结束当前路径的探索
        return;
    }
    
    // 尝试在下一列不放置皇后，继续搜索
    // 不放皇后
    dfs(x + 1, y, Q);

    // 尝试在当前列放置皇后
    // 放皇后
    if (!row[y] && !col[x] && !dg[x + y] && !udg[n + y - x]) {
        // 在当前位置放置皇后，更新相应位置的标记
        map[y][x] = 'Q';
        row[y] = col[x] = dg[x + y] = udg[n + y - x] = true;
        
        // 继续搜索下一列，放置下一个皇后
        dfs(x + 1, y, Q + 1);
        
        // 回溯，撤销当前位置的皇后，恢复标记
        map[y][x] = '.';
        row[y] = col[x] = dg[x + y] = udg[n + y - x] = false;
    }
}
int main(){
    cin>>n;
    foe(i,0,n-1)foe(j,0,n-1){
        map[i][j]='.';
    }
    dfs(0,0,0);
    return 0;
}