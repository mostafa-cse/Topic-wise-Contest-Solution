#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m;

    while (cin >> n >> m) {
        vector<int> adj[n + 1], indeg(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            indeg[y]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (!indeg[i]) q.push(i);
        }

        vector<int> ans;
        while (q.size()) {
            int val = q.front();
            q.pop();
            ans.push_back(val);
            for (int v : adj[val]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (ans.size() == n) {
            for (int i : ans)
                cout << i << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}