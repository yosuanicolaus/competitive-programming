#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[1001];

auto solve() {
    int n;
    cin >> n;

    dp[0] = 0;
    for (int i = 1; i <= 1000; i++) {
        dp[i] = max(i, dp[i / 2] + dp[i / 3] + dp[i / 4]);
    }

    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cout << solve() << '\n';
    return 0;
}
