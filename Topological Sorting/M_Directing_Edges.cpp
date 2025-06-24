#include <bits/stdc++.h>
#define int long long
using namespace std;
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1], in(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        adj[u].push_back(v);
        if (t) adj[v].push_back(u);
        if (!t) in[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    vector<pair<int, int>> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                ans.push_back({u, v});
                q.push(v);
            }
        }
    }
    dout(ans);
}
signed main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}