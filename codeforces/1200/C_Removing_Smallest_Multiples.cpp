#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string binary_t;
    cin >> n >> binary_t;

    vector<bool> set_s(n + 1, true), set_t(n + 1);

    for (int i = 0; i < n; i++) {
        if (binary_t[i] == '1') set_t[i + 1] = true;
    }

    ll operation = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (set_t[j] == true) break;
            if (set_s[j] == true) {
                set_s[j] = false;
                operation += i;
            }
        }
    }
    cout << operation << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
