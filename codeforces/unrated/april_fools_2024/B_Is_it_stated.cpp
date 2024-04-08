#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'i' && s[i + 1] == 't') {
            std::cout << "YES" << "\n";
            return;
        }
    }
    std::cout << "NO" << "\n";
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
