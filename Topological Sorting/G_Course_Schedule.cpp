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

        adj[x].push_back(y);
        indeg[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty()) {
        int val = q.front();
        q.pop();

        for (int v : adj[val]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
        ans.push_back(val);
    }
    if (ans.size() == n) {
        for (int i : ans) {
            cout << i << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}