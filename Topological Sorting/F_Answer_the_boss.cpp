#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Function to solve each test case
void solve(int testCase, int N, int R, vector<pair<int, int>> &relations)
{
    vector<vector<int>> adj(N); // Adjacency list
    vector<int> inDegree(N, 0); // In-degree of each node

    // Build the graph and calculate in-degrees
    for (auto &relation : relations)
    {
        int lower = relation.first;
        int higher = relation.second;
        adj[higher].push_back(lower);
        inDegree[lower]++;
    }

    // Priority queue to ensure lexicographical order
    priority_queue<int, vector<int>, greater<int>> pq;

    // Add nodes with in-degree 0 to the priority queue
    for (int i = 0; i < N; i++)
    {
        if (inDegree[i] == 0)
        {
            pq.push(i);
        }
    }

    vector<pair<int, int>> result; // To store the rank and employee pairs
    int rank = 1;

    while (!pq.empty())
    {
        int size = pq.size();
        vector<int> currentRank;

        // Process all nodes of the current rank
        for (int i = 0; i < size; i++)
        {
            int node = pq.top();
            pq.pop();
            currentRank.push_back(node);

            // Reduce in-degree of neighbors and add them to the queue if in-degree becomes 0
            for (int neighbor : adj[node])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                {
                    pq.push(neighbor);
                }
            }
        }

        // Sort employees of the current rank lexicographically
        sort(currentRank.begin(), currentRank.end());

        // Add the current rank employees to the result
        for (int employee : currentRank)
        {
            result.push_back({rank, employee});
        }

        rank++;
    }

    // Output the result for the current test case
    cout << "Scenario #" << testCase << ":\n";
    for (auto &entry : result)
    {
        cout << entry.first << " " << entry.second << "\n";
    }
    // cout << "\n"; // Blank line for separation
}

int main()
{
    int T; // Number of test cases
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int N, R; // Number of employees and relations
        cin >> N >> R;

        vector<pair<int, int>> relations(R);
        for (int i = 0; i < R; i++)
        {
            cin >> relations[i].first >> relations[i].second;
        }

        solve(t, N, R, relations);
    }

    return 0;
}