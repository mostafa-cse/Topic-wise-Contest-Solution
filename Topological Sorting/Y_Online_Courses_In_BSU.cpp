#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;

    set<int> a;
    for (int i = 0; i < k; ++i) {
        int c;
        cin >> c;
        a.insert(c);
    }

    vector<int> adj[n + 1], in(n + 1, 0);
    for (int u = 1; u <= n; u++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int v;
            cin >> v;
            adj[v].push_back(u);
            in[u]++;
        }
    }

    vector<int> par(n + 1, -1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            par[i] = 0;
            q.push(i);
        }
    }
    if (q.empty()) {
        return cout << -1, 0;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (--in[v] == 0) {
                par[v] = u;
                q.push(v);
            }
        }
    }

    set<int> ans;
    for (int u : a) {
        ans.insert(u);
        while (u > 0) {
            u = par[u];
            ans.insert(u);
        }
    }

    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}