#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    int highest_count = 0;

    std::map<int, int> num_count;

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        num_count[num]++;
        if (num_count[num] > highest_count) {
            highest_count = num_count[num];
        }
    }

    int opr_swap = n - highest_count;
    int opr_copy = 0;
    int swapped = 0;

    while (swapped < opr_swap) {
        opr_copy++;
        swapped += highest_count;
        highest_count *= 2;
    }

    std::cout << opr_swap + opr_copy << '\n';
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
