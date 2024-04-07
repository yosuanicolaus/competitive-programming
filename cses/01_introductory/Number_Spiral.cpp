#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 240407 - https://cses.fi/problemset/task/1071/
// be careful with pow(num, 2) function
// when dealing with very high numbers, it might introduce rounding errors

void solve() {
    ll y, x;
    cin >> y >> x;

    bool calc_vert = y < x;
    ll high_num = max(y, x);
    ll low_num = min(y, x);
    ll high_bound = (high_num * high_num) + 1;
    ll low_bound = (high_num - 1) * (high_num - 1);

    ll ans;
    if (high_num % 2 == 0) {
        // spiral goes down left
        if (calc_vert) {
            ans = low_bound + low_num;
        } else {
            ans = high_bound - low_num;
        }
    } else {
        // spiral goes right up
        if (calc_vert) {
            ans = high_bound - low_num;
        } else {
            ans = low_bound + low_num;
        }
    }
    cout << ans << '\n';
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
