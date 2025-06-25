#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1], indeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        adj[y].push_back(x);
        indeg[x]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> ans;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();

        ans.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) {
                pq.push(v);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}