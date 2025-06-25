#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;

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
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }


    set<int> st;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) st.insert(i);
    }

    vector<int> ans;
    while (st.size()) {
        int val = *st.begin();
        ans.push_back(val);
        for (int v : adj[val]) {
            in[v]--;
            if (in[v] == 0) {
                st.insert(v);
            }
        }
        st.erase(val);
    }

    for (int i : ans)
        cout << i << " ";
    return 0;
}