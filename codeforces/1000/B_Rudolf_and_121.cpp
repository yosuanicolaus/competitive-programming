#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        nums[i] = a;
    }

    for (int i = 0; i < n - 2; i++) {
        int num = nums[i];
        // force flat the next num based on current num
        nums[i] = 0;
        nums[i + 1] -= 2 * num;
        nums[i + 2] -= num;

        if (nums[i + 1] < 0 || nums[i + 2] < 0 ||
            (i == n - 3 && (nums[i + 1] != 0 || nums[i + 2] != 0))) {
            std::cout << "NO" << "\n";
            return;
        }
    }

    std::cout << "YES" << "\n";
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
