#include <bits/stdc++.h>
using namespace std;

// 定义一些常用的宏和常量
#define endl '\n'
#define int long long
const int N = 1e7 + 10;  // 定义数组的最大大小
const int M = 2e5 + 10;  // 定义另一个数组的最大大小
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> PII;
const int mod = 998244353;
const int INF = 1e9;
const double eps = 1e-6;

// 定义一些全局变量
int prime[N], vis[N];  // prime数组用于存储素数，vis数组用于标记是否为合数
int cnt = 0;  // 素数的计数器
int sg[N];  // sg数组用于存储每个数的sg值

// 欧拉筛法，用于预处理素数和sg值
void Ola()
{
	sg[1] = 1;  // 1的sg值为1
	for (int i = 2; i < N; i++)
	{
		if (!vis[i])  // 如果i是素数
			prime[++cnt] = i, sg[i] = cnt;  // 记录素数，并设置sg值为素数计数器的值
		if (i % 2 == 0)  // 如果i是偶数
			sg[i] = 0;  // 偶数的sg值为0
		for (int j = 1; j <= cnt && i * prime[j] < N; j++)
		{
			vis[i * prime[j]] = 1;  // 标记i * prime[j]为合数
			if (i * prime[j] % 2 == 1)  // 如果i * prime[j]是奇数
				sg[i * prime[j]] = sg[prime[j]];  // 设置sg值为prime[j]的sg值
			if (i % prime[j] == 0)  // 如果i能被prime[j]整除
				break;  // 跳出循环，避免重复标记
		}
	}
}

// 解决每个测试用例的函数
void solve()
{
	int n;
	cin >> n;  // 读取堆的数量
	int ans = 0;  // 初始化答案为0
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;  // 读取每堆蛋糕的数量
		ans ^= sg[x];  // 计算sg值的异或和
	}
	if (ans == 0)  // 如果异或和为0
		cout << "zyfgg\n";  // 后手玩家获胜
	else
		cout << "zcygg\n";  // 先手玩家获胜
}

// 主函数
signed main()
{
	// freopen("out.txt", "w", stdout);  // 用于输出重定向到文件
	ios::sync_with_stdio(false);  // 关闭同步，提高输入输出效率
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;  // 读取测试用例的数量
	Ola();  // 预处理素数和sg值
	while (T--)
		solve();  // 处理每个测试用例
	return 0;
}
