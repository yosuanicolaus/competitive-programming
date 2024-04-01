#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int x, n;
    std::cin >> x >> n;
    int ans = 1;

    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (n <= x / i) {
                ans = std::max(ans, i);
            }
            if (n <= i) {
                ans = std::max(ans, x / i);
            }
        }
    }

    std::cout << ans << "\n";
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
