#if LOCAL
#include "template/debug.h"
#else /*©[yosuanicolaus]©*/
#define d(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<string> vecstr(n);
    unordered_set<string> setstr;
    string ans;

    for (int i = 0; i < n; i++) {
        cin >> vecstr[i];
        setstr.insert(vecstr[i]);
    }

    for (const auto &str : vecstr) {
        int len = str.size();
        if (len == 1) {
            ans += '0';
            continue;
        }
        bool found = false;
        for (int i = 1; i < len; i++) {
            string s1 = str.substr(0, i);
            string s2 = str.substr(i, 8);
            if (setstr.count(s1) && setstr.count(s2)) {
                ans += '1';
                found = true;
                break;
            }
        }
        if (!found) ans += '0';
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
