#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1], in(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        in[v]++;
    }

    int ans = 0;
    vector<int> order, vis(n + 1, 0);
    function<void(int, bool)> dfs = [&](int u, bool ok) -> void {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, false);
            }
        }
        if (ok) order.push_back(u);
    };
    
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