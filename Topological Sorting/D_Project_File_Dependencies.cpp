#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m;

    while(cin >> n >> m) {
        vector<int> adj[n + 1], in(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int v, k;
            cin >> v >> k;
            for (int j = 0; j < k; j++) {
                int u;
                cin >> u;
                in[v]++;
                adj[u].push_back(v);
            }
        }
    
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
    
            cout << u << " ";
            for (int v : adj[u]) {
                in[v]--;
                if (in[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
    return 0;
}