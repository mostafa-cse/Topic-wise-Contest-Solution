#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> adj(N);
        vector<int> deg(N, 0);

        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        if (N <= 1) {
            cout << 0 << "\n";
            continue;
        }

        queue<int> q;
        vector<bool> removed(N, false);
        for (int i = 0; i < N; i++) {
            if (deg[i] == 1) {
                q.push(i);
                removed[i] = true;
            }
        }

        while (!q.empty()) {
            int leaf = q.front(); 
            q.pop();
            for (int nei : adj[leaf]) {
                if (!removed[nei]) {
                    deg[nei]--;
                }
            }
        }

        int Lprime = 0;
        for (int i = 0; i < N; i++) {
            if (!removed[i] && deg[i] == 1) {
                Lprime++;
            }
        }

        int ans = (Lprime + 1) / 2;
        ans = max(ans, 1);
        cout << ans << "\n";
    }
    return 0;
}
