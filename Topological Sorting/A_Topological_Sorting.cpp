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

    set<int> st;
    for (int i = 1; i <= n; i++) {
        if (!indeg[i]) st.insert(i);
    }

    vector<int> ans;
    while (st.size()) {
        int val = *st.begin();
        ans.push_back(val);
        for (int v : adj[val]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                st.insert(v);
            }
        }
        st.erase(val);
    }

    if (ans.size() == n) {
        for (int i : ans) cout << i << " ";
    } else {
        cout << "Sandro fails.";
    }
    return 0;
}