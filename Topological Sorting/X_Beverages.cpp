#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int tc = 0;
    int n;
    while (cin >> n) {
        map<string, int> beverages;
        map<int, string> store;
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            store[cnt] = s;
            beverages[s] = cnt++;
        }

        int m;
        cin >> m;
        map<int, vector<int>> adj;
        map<int, int> in;
        for (int i = 0; i < m; i++) {
            string u, v;
            cin >> u >> v;

            adj[beverages[u]].push_back(beverages[v]);
            in[beverages[v]]++;
        }

        priority_queue<int> q;
        for (auto [f, s] : beverages) {
            if (in.count(beverages[f]) == 0) {
                q.push(-beverages[f]);
            }
        }

        cout << "Case #" << ++tc << ": Dilbert should drink beverages in this order:";
        while (!q.empty()) {
            int u = -q.top();
            q.pop();
            cout << " " << store[u];
            for (auto v : adj[u]) {
                if (--in[v] == 0) {
                    q.push(-v);
                } 
            }
        }
        cout << "." << endl << endl;
    }
    return 0;
}