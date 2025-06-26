#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> t[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        t[u].push_back(v);
    }

    vector<int> vis(n + 1, 0);
    stack<int> nodes;
    function<void(int, bool)> dfs = [&](int u, bool ok) -> void {
        vis[u] = 1;
        for (int v : t[u]) {
            if (!vis[v]) {
                dfs(v, ok);
            }
        }
        if (ok) nodes.push(u);
    };
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, true);
        }
    }

    fill(vis.begin(), vis.end(), 0);
    int ans = 0;
    while (!nodes.empty()) {
        if (!vis[nodes.top()]) {
            ans++;
            dfs(nodes.top(), 0);
        }
        nodes.pop();
    }
    cout << ans << endl;
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}