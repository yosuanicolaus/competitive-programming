#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// TLE
// https://cses.fi/problemset/task/1091

auto solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> tickets(n);
    vector<bool> taken(n, false);

    for (int i = 0; i < n; i++)
        cin >> tickets[i];
    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < m; i++) {
        ll customer;
        cin >> customer;
        auto it = upper_bound(tickets.begin(), tickets.end(), customer);
        it--;
        int dist = distance(tickets.begin(), it);
        while (dist >= 0 && taken[dist]) {
            dist--;
        }
        if (dist == -1) {
            cout << -1 << '\n';
        } else {
            cout << tickets[dist] << '\n';
            taken[dist] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
