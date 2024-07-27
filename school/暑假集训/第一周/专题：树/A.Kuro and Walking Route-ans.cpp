#include <bits/stdc++.h>

using namespace std;

const int N = 300010, M = 600010;

struct edge {
    int to, next;
} e[M];

int head[N], idx;

void add(int u, int v) {
    idx++, e[idx].to = v, e[idx].next = head[u], head[u] = idx;
}

int n, x, y;
int sz[N];

bool dfs(int u, int fa) {
    bool flag = (u == y);
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int to = e[i].to;
        if (to == fa) continue;
        bool d = dfs(to, u);
        if (!d) sz[u] += sz[to];
        flag |= d;
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >>n >> x >> y;

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    dfs(x, 0);
    cout << 1ll * n * (n - 1) - 1ll * sz[x] * sz[y] << '\n';
    return 0;
}