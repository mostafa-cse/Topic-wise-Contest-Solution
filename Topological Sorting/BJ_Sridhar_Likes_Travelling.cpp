#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    map<string, vector<pair<string, int>>> adj;
    set<string> store;
    map<string, int> in;

    for (int i = 0; i < n - 1; i++)
    {
        string u, v;
        int w;
        cin >> u >> v >> w;
        in[v]++;
        adj[u].push_back({v, w});
        store.insert(u);
        store.insert(v);
    }

    queue<string> q;
    for (auto i : store)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    int cost = 0;
    vector<tuple<string, string, int>> ans;

    while (!q.empty())
    {
        string u = q.front();
        q.pop();

        for (auto [v, w] : adj[u])
        {
            in[v]--;
            if (in[v] == 0)
            {
                ans.push_back({u, v, w});
                q.push(v);
                cost += w;
            }
        }
    }

    for (auto [a, b, c] : ans)
    {
        cout << a << " " << b << " " << c << endl;
    }
    cout << cost << "$" << endl;
}

signed main()
{
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}