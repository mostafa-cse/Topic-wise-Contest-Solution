#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> G1[N], G2[N];
queue<int> q;
int n1, m1, n2, m2;
int deg1[N], deg2[N];
bool cnt1[N][N], cnt2[N][N], ans[N];

int main() {
    scanf("%d%d%d%d", &n1, &n2, &m1, &m2);

    for (int i = 1; i <= m1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G1[u].push_back(v);
        deg1[v]++;
    }

    for (int i = 1; i <= m2; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G2[u].push_back(v);
        deg2[v]++;
    }

    queue<int> q1, q2;

    for (int i = 1; i <= n1; i++) {
        if (!deg1[i]) {
            q1.push(i);
        }
    }

    for (int i = 1; i <= n2; i++) {
        if (!deg2[i]) {
            q2.push(i);
        }
    }

    cnt1[1][0] = 1;

    while (!q1.empty()) {
        int u = q1.front();
        q1.pop();

        for (auto v : G1[u]) {
            if (--deg1[v] == 0) {
                q1.push(v);
            }

            for (int i = 0; i <= n1; i++) {
                if (cnt1[u][i]) {
                    cnt1[v][i + 1] = 1;
                }
            }
        }
    }

    cnt2[1][0] = 1;

    while (!q2.empty()) {
        int u = q2.front();
        q2.pop();

        for (auto v : G2[u]) {
            if (--deg2[v] == 0) {
                q2.push(v);
            }

            for (int i = 0; i <= n2; i++) {
                if (cnt2[u][i]) {
                    cnt2[v][i + 1] = 1;
                }
            }
        }
    }

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (cnt1[n1][i] && cnt2[n2][j]) {
                ans[i + j] = 1;
            }
        }
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        int step;
        scanf("%d", &step);

        if (ans[step]) {
            puts("Yes");
        } else {
            puts("No");
        }
    }

    return 0;
}
