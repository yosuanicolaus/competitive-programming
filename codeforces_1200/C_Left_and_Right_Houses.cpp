#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    string a;
    cin >> n >> a;
    int tc0 = 0, tc1 = 0, c0 = 0, c1 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == '0')
            tc0++;
        else
            tc1++;
    }

    int best_i = (tc0 <= tc1) ? 0 : n;
    int prev_dist = abs(n - 2 * best_i);

    for (int i = 0; i < n - 1; i++) {
        if (a[i] == '0') {
            c0++;
            tc0--;
        } else {
            c1++;
            tc1--;
        }
        int new_i = i + 1;

        if (c0 >= c1 && tc0 <= tc1) {
            int new_dist = abs(n - 2 * new_i);
            if (new_dist < prev_dist) {
                best_i = new_i;
                prev_dist = new_dist;
            } else if (new_dist == prev_dist && new_i < best_i) {
                best_i = new_i;
                prev_dist = new_dist;
            }
        }
    }

    cout << best_i << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
