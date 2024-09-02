/**
 *    author: A K M S Limon
 *    created: 02-September-2024  23:28:22
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> pre1(26, 0), pre2(26, 0);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                pre1[s[i] - 'a']++;
            }
            else {
                pre2[s[i] - 'a']++;
            }
        }
        int mx1 = INT_MIN, mx2 = INT_MIN;
        for (int i = 0; i < 26; i++) {
            mx1 = max(pre1[i], mx1);
            mx2 = max(pre2[i], mx2);
        }
        if (n % 2 == 0) {
            cout << n - mx1 - mx2 << '\n';
            continue;
        }
        vector<int> pre3(26, 0), pre4(26, 0);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                pre1[s[i] - 'a']--;
            }
            else {
                pre2[s[i] - 'a']--;
            }
            mx1 = INT_MIN, mx2 = INT_MIN;
            for (int i = 0; i < 26; i++) {
                mx1 = max(mx1, pre1[i] + pre4[i]);
                mx2 = max(mx2, pre2[i] + pre3[i]);
            }
            ans = min(ans, n - mx1 - mx2);
            if (i % 2 == 0) {
                pre3[s[i] - 'a']++;
            }
            else {
                pre4[s[i] - 'a']++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}