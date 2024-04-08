#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> heights(n + 1), prefix_max(n + 1);
    heights[0] = 0;
    prefix_max[0] = 0;

    for (int i = 1; i <= n; i++) {
        ll step;
        cin >> step;
        heights[i] = heights[i - 1] + step;
        prefix_max[i] = max(prefix_max[i - 1], step);
    }

    for (int i = 0; i < q; i++) {
        ll leg_size;
        cin >> leg_size;

        int l = 0, r = n;
        int best_idx = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (prefix_max[m] <= leg_size) {
                best_idx = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        cout << heights[best_idx] << ' ';
    }
    cout << '\n';
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
