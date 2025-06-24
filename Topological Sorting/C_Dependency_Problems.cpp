#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, vector<string>> g;
    map<string, int> Parent, ind;
    set<string> st;

    string v;
    while (cin >>  v) {
        st.insert(v);
        Parent[v] = 1;

        string u;
        while (cin >> u) {
            if (u == "0") break;
            ind[v]++;
            st.insert(u);
            g[u].push_back(v);
        }
    }

    queue<string> q;
    for (auto i : st) {
        if (ind[i] == 0 && Parent[i] == 1) {
            cout << i << endl;
            q.push(i);
        }
    }

    int ans = 0;
    while (!q.empty()) {
        string u = q.front();
        q.pop();

        if (Parent[u]) cerr << u << " ", ans++;

        for (auto v : g[u]) {
            ind[v]--;
            if (ind[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << ans;
    return 0;
}
