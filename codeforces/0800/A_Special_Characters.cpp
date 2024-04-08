#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    if (n % 2 == 1) {
        std::cout << "NO" << "\n";
        return;
    }

    bool flag = true;
    std::string res;

    for (int i = 0; i < n / 2; i++) {
        if (i % 2 == 0) {
            res.append("AA");
        } else {
            res.append("BB");
        }
    }

    std::cout << "YES" << "\n";
    std::cout << res << "\n";
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
