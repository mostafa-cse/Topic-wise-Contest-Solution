#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    string s;
    vector<string> a;
    
    map<char, int> indeg;
    while (cin >> s and s != "#") {
        a.push_back(s);
        for (char c : s) {
            indeg[c] = 0;
        }
    }

    map<char, vector<char>> adj;
    for (int i = 0; i < a.size() - 1; i++) {
        string A = a[i];
        string B = a[i + 1];
        for (int j = 0; j < min(A.size(), B.size()); ++j) {
            if (A[j] != B[j]) {
                adj[A[j]].push_back(B[j]);
                indeg[B[j]]++;
                break;
            }
        }
    }

    queue<char> q;
    for (auto [f, s] : indeg) {
        if (s == 0) {
            q.push(f);
        }
    }

    string ans = "";
    while (!q.empty()) {
        char u = q.front();
        q.pop();

        ans += u;
        for (char v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << ans << endl;
    return 0;
}