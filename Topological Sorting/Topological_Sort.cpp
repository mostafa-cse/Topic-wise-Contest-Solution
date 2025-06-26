#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Mod = 998244353;
int modexpo(int a, int p,int mod) {
    int res = 1;
    while (p) {
        if(p & 1) {
            res = (a * res) % mod;
        }
        p >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
signed main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n <= 2) {
        cout << 1 << endl;
    } else if (n == 3) {
        cout << 4 << endl;
    } else {
        cout << modexpo(4, n, Mod) << endl;
    }
    return 0;
}