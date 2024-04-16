#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll f = lcm(b, d);
    a *= (f / b);
    c *= (f / d);
    ll e = a + c;
    ll g = gcd(e, f);
    e /= g;
    f /= g;
    cout << e << ' ' << f << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
