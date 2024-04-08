#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);

    unordered_map<int, int> a_map;
    unordered_map<int, int> b_map;
    ll status = 0;
    int good_count = 0;

    for (int i = 0; i < n; i++) {
        int anum;
        cin >> anum;
        a[i] = anum;
        if (i < m) a_map[anum]++;
    }
    for (int i = 0; i < m; i++) {
        int bnum;
        cin >> bnum;
        b[i] = bnum;
        b_map[bnum]++;
    }

    for (auto &[bnum, bcount] : b_map) {
        if (a_map[bnum]) status += min(a_map[bnum], bcount);
    }
    if (status >= k) good_count++;

    for (int i = 1; i < n - m + 1; i++) {
        int loss_num = a[i - 1];
        int gain_num = a[i + m - 1];
        a_map[loss_num]--;
        if (a_map[loss_num] < b_map[loss_num]) status--;
        a_map[gain_num]++;
        if (a_map[gain_num] <= b_map[gain_num]) status++;
        if (status >= k) good_count++;
    }

    cout << good_count << '\n';
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
