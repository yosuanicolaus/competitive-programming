#if LOCAL
#include "template/debug.h"
#else
#define d(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int p1, p2, p3, p4;
    cin >> p1 >> p2 >> p3 >> p4;

    int ans = p1 / 2 + p2 / 2 + p3 / 2 + p4 / 2;
    ans += ((p1 % 2) & (p2 % 2) & (p3 % 2));
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
