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
    cin >> n;

    unordered_map<ll, ll> color_minval;
    for (int i = 0; i < n; i++) {
        ll a, c;
        cin >> a >> c;

        if (color_minval[c] == 0) {
            color_minval[c] = a;
        } else {
            color_minval[c] = min(color_minval[c], a);
        }
    }

    ll best = 0;
    for (const auto &cvpair : color_minval) {
        best = max(best, cvpair.second);
    }
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
