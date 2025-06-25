#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m;
    while (cin >> n >> m and n != 0) {
        vector<int> adj[n + 1], in(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            in[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans.push_back(u);
            
            for (int v : adj[u]) {
                if (--in[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (ans.size() == n) {
            for (int i : ans) {
                cout << i << endl;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}