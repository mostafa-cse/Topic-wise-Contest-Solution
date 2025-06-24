#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 29;

ll n, m, c, s[N], used[N];
vector<pair<ll, ll>> g[N];
vector<ll> rG[N];
vector<ll> topsort;

void dfs(ll v) {
    used[v] = 1;
    for (auto to : rG[v]) {
        if (used[to]) continue;
        dfs(to);
    }
    topsort.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);

    cin >> n >> m >> c;
    for (ll i = 1; i <= n; ++i) cin >> s[i];
    for (ll i = 1; i <= c; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        rG[v].push_back(u);
    }
    for (ll i = 1; i <= n; ++i) {
        if (!used[i]) dfs(i);
    }
    for (ll u : topsort) {
        for (auto [v, w] : g[u]) {
            s[v] = max(s[v], s[u] + w);
        }
    }
    for (ll i = 1; i <= n; ++i) cout << s[i] << '\n';
    return 0;
}