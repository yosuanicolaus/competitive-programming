#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll L, R;
    cin >> L >> R;
    vector<pair<ll, ll>> ans;
    if (L % 2 == 1) {
        ans.push_back({L, L + 1});
        L++;
    }

    ll adder = 2;
    if (L == 0) {
        while (L + adder <= R)
            adder *= 2;
        adder /= 2;
        ans.push_back({L, L + adder});
        L += adder;
        adder = 2;
    }

    while (L != R) {
        while (L + adder <= R && (L + adder <= L * 2)) {
            adder *= 2;
        }
        adder /= 2;
        ans.push_back({L, L + adder});
        L += adder;
        adder = 2;
    }

    cout << ans.size() << '\n';
    for (const auto &[l, r] : ans) {
        cout << l << ' ' << r << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
