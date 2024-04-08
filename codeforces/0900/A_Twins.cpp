#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int total = 0;
    std::priority_queue<int> coins;

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        total += a;
        coins.push(a);
    }

    double mid_point = total / 2.0;
    int coin_count = 0;
    int total_value = 0;

    while (total_value <= mid_point) {
        coin_count++;
        total_value += coins.top();
        coins.pop();
    }

    std::cout << coin_count << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
