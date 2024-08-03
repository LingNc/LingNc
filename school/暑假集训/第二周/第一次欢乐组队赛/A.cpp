#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
void  solve() {
	int n, s, v;
	cin >> n >> s >> v;
	if (s * v >= n) cout << "1" << endl;
	else cout << "0" << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}