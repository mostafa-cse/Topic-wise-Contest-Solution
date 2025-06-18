#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    set<string> ig;
    multimap<string, string> res;
    string s;
    while (getline(cin, s) and s != "::") {
        ig.insert(s);
    }

    while (getline(cin, s)) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (int i = 0; i < s.size(); i++) {
            if (!isalpha(s[i])) 
                continue;

            int j = i;
            string w = "";
            while (j < s.size() && isalpha(s[j])) {
                w += s[j];
                j++;
            }

            if (!ig.count(w)) {
                transform(w.begin(), w.end(), w.begin(), ::toupper);
                string temp = s;
                temp.replace(i, w.size(), w);
                res.insert({w, temp});
            }
            i = j;
        }
    }
    for (const auto &it : res) {
        cout << it.second << endl;
    }
    return 0;
}