#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// with editorial help
// lesson: learn math, get the simple formula
// LCM & GCD

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 2), b(n + 2);
    a[0] = 1;
    a[n + 1] = 1;
    b[0] = 1;

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
        b[i] = lcm(a[i - 1], a[i]);
    }
    b[n + 1] = lcm(a[n], a[n + 1]);

    for (int i = 1; i <= n; i++) {
        if (a[i] != gcd(b[i], b[i + 1])) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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
