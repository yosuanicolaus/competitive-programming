#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int ans;
    if (a * 2 <= b) {
        ans = n * a;
    } else {
        int remain = n % 2;
        if (remain) n -= 1;
        ans = (n / 2) * b;
        if (remain) ans += a;
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
