#include <bits/stdc++.h>
using ll = long long;

void solve() {
    ll n, k;
    std::cin >> n >> k;

    ll even_start = n / 2;
    if (n % 2 == 1) {
        even_start++;
    }

    ll ans;
    if (k < even_start + 1) {
        // odd range
        ans = 2 * k - 1;
    } else {
        // even range
        k -= even_start;
        ans = 2 * k;
    }

    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
