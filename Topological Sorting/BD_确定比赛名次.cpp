#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1], indeg(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        indeg[y]++;
    }

    set<int> st;
    vector<vector<int>> ans;
    vector<int> tem = indeg;
    for (int i = 1; i <= n; i++)
    {
        if (!tem[i])
        {
            st.insert(i);
            vector<int> tem;
            while (st.size())
            {
                int val = *st.begin();
                tem.push_back(val);
                for (int v : adj[val])
                {
                    indeg[v]--;
                    if (indeg[v] == 0)
                    {
                        st.insert(v);
                    }
                }
                st.erase(val);
            }
            ans.push_back(tem);
        }
    }

    sort(ans.begin(), ans.end(), [&](vector<int> &x, vector<int> &y)
         { if (x.size() == y.size()) return x[0] < y[0];
            return x.size() < y.size(); });

    for (auto ar : ans)
    {
        for (int i : ar)
        {
            cout << i << " ";
        }
    }
    return 0;
}