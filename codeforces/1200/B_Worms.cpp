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
    vector<ll> labels(n + 1);
    labels[0] = 0;

    for (int i = 1; i <= n; i++) {
        ll label;
        cin >> label;
        labels[i] = labels[i - 1] + label;
    }

    int m;
    cin >> m;
    while (m--) {
        ll label;
        cin >> label;
        auto itr = lower_bound(labels.begin(), labels.end(), label);
        cout << distance(labels.begin(), itr) << '\n';
        // alternate binary search solution (manual)
        // https://codeforces.com/problemset/submission/474/255161995
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
