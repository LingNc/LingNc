#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int a[N];
void  solve() {
	int n, x1, x2;
	cin >> n >> x1;
	for (int i = 0;i < n - 1;i++) {
		cin >> x2;
		a[i] = x1 - x2;
		x1 = x2;
	}
	sort(a, a + n - 1);
	int m;
	for (int i = 1;i < n - 1;i++)
		a[i] += a[i - 1];
	cin >> m;
	while (m--) {
		int op, x;
		cin >> op >> x;
		if (op) cout << a[n - 1 - x] << endl;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}