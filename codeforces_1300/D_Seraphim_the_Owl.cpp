#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> replace_costs(n), overtake_costs(n);

    for (int i = 0; i < n; i++) {
        i64 coin;
        std::cin >> coin;
        replace_costs[i] = coin;
    }
    for (int i = 0; i < n; i++) {
        i64 coin;
        std::cin >> coin;
        overtake_costs[i] = coin;
    }

    i64 final_cost = replace_costs[m - 1];
    int test_m = m - 2;
    while (test_m >= 0) {
        i64 test_new_final_cost =
            replace_costs[test_m] + overtake_costs[test_m + 1];
        overtake_costs[test_m] += overtake_costs[test_m + 1];
        if (test_new_final_cost < final_cost) {
            final_cost = test_new_final_cost;
        }
        test_m--;
    }

    i64 journey_cost = 0;
    for (int i = m; i < n; i++) {
        journey_cost += std::min(replace_costs[i], overtake_costs[i]);
    }

    std::cout << final_cost + journey_cost << "\n";
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
