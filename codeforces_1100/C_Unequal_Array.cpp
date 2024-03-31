#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int prev = -1;
    int eq_left = -1;
    int eq_right = -1;

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;

        if (prev == a && eq_left == -1) {
            eq_left = i;
        } else if (prev == a) {
            eq_right = i - 1;
        }
        prev = a;
    }

    if (eq_left == -1 || eq_right == -1) {
        std::cout << 0 << "\n";
    } else {
        int ans = eq_right - eq_left;
        if (ans == 0)
            ans = 1;
        std::cout << ans << "\n";
    }
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
