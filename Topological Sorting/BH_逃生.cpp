#include <bits/stdc++.h>
#define int long long
using namespace std;

// Custom hash function for std::pair
struct pair_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // Combine the two hashes
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    unordered_set<pair<int, int>, pair_hash> mark; // Use custom hash function
    vector<int> adj[n + 1];
    vector<int> in(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (mark.count({u, v}))
        {
            continue;
        }
        mark.insert({u, v});
        adj[u].push_back(v);
        in[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adj[u])
        {
            in[v]--;
            if (in[v] == 0)
            {
                q.push(v);
            }
        }
    }

    // Check if all nodes are processed
    if (result.size() != n)
    {
        assert(0);
        return;
    }

    for (int u : result)
    {
        cout << u << " ";
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}