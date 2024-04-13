#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    int total = 0;
    int operation = n * 2 - 1;

    int nn = 1;
    while (nn <= n) {
        total += (nn * 2 - 1) * nn;
        nn++;
    }

    string perms;
    for (int i = 1; i <= n; i++) {
        perms += (i == n) ? to_string(i) : to_string(i) + ' ';
    }

    cout << total << ' ' << operation << '\n';
    cout << "1 " << n << ' ' << perms << '\n';
    nn = n - 1;
    while (nn > 0) {
        cout << "1 " << nn << ' ' << perms << '\n';
        cout << "2 " << nn << ' ' << perms << '\n';
        nn--;
    }
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
