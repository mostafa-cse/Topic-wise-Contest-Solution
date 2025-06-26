#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n1, n2, m1, m2;
    cin >> n1 >> n2 >> m1 >> m2;

    vector<vector<int>> adj(n1 + n2 + 1);
    vector<int> in(n1 + n2 + 1, 0);
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    adj[n1].push_back(n1 + 1);
    in[n1 + 1] = 1;
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        adj[u + n1].push_back(v + n1);
        in[v + n1]++;
    }
    
    queue<int> q;
    // node, level
    map<int, int> lvl[n1 + n2 + 1], Ans;
    q.push(1);
    lvl[1][0] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            for (auto [f, s] : lvl[u]) {
                lvl[v][f + 1] = 1;
                if (v == n1 + n2) Ans[f + 1] = 1;
            }
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (Ans[t + 1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}