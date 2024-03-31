#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    std::string digits;
    std::cin >> digits;

    int c0 = 0;
    int c1 = 0;

    for (int i = 0; i < digits.length(); i++) {
        if (digits[i] == '0') {
            c0++;
            c1 = 0;
        } else {
            c1++;
            c0 = 0;
        }

        if (c0 == 7 || c1 == 7) {
            std::cout << "YES" << "\n";
            return;
        }
    }

    std::cout << "NO" << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
