#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif

signed main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> adj[n], in(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        adj[u].push_back(v);
        in[v]++;
    }
    
    queue<int> q;
    vector<vector<int>> cnt(n, vector<int>(26, 0));
    for (int i = 0; i < n; i += 1) {
        if (in[i] == 0) {
            q.push(i);
            cnt[i][s[i] - 'a']++;
        }
    }

    int p = n;
    while (!q.empty()) {
        p--;
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            in[v]--;
            for (int c = 0; c < 26; c++) {
                cnt[v][c] = max(cnt[v][c], cnt[u][c]);
            }
            cnt[v][s[v] - 'a'] = max(cnt[v][s[v] - 'a'], cnt[u][s[v] - 'a'] + 1);

            if (in[v] == 0) {
                q.push(v);
            }
        }
    }

    if (p) {
        cout << -1;
    } else {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 26; c++) {
                ans = max(ans, cnt[i][c]);
            }
        }
        cout << ans;
    }
    return 0;
}
