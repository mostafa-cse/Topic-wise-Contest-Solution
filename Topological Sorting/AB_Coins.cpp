#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    map<char, vector<char>> adj;
    char a, b, c;
    map<char, int> in;
    set<char> store;
    while (cin >> a >> b >> c) {
        store.insert(a);
        store.insert(c);
        if (b == '>') {
            swap(a, c);
        }
        adj[a].push_back(c);
        in[c]++;
    }

    queue<char> q;
    for (auto c : store) {
        if (in[c] == 0) {
            q.push(c);
        }
    }
    
    string ans = "";
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        ans += u;
        for (auto v : adj[u]) {
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }
    if (ans.size() != store.size()) {
        cout << "Impossible";
    } else {
        cout << ans;
    }
    return 0;
}