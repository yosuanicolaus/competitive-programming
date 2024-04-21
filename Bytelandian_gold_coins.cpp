#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[500'000'001];

auto solve() {
    for (int i = 1; i <= 500'000'000; i++) {
        dp[i] = max(i, dp[i / 2] + dp[i / 3] + dp[i / 4]);
    }

    int n;
    while (cin >> n) {
        cout << dp[n] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
