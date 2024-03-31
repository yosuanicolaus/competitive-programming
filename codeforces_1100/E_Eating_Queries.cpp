#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> candies(n);
    int candy_sum = 0;

    for (int i = 0; i < n; i++) {
        int candy;
        std::cin >> candy;
        candies[i] = candy;
        candy_sum += candy;
    }

    std::sort(candies.rbegin(), candies.rend());
    // convert candies to prefix sum for efficient binary search
    for (int i = 1; i < n; i++) {
        candies[i] += candies[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int query;
        std::cin >> query;
        if (query > candy_sum) {
            std::cout << -1 << "\n";
            continue;
        }

        int l = 0;
        int r = n - 1;

        while (l < r) {
            int m = (l + r) / 2;

            if (query < candies[m]) {
                r = m;
            } else if (query > candies[m]) {
                l = m + 1;
            } else {
                r = m;
                break;
            }
        }

        std::cout << r + 1 << "\n";
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
