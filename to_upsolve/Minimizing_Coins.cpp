#if LOCAL
#include "template/debug.h"
#else
#define d(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int memo[(int)1e6 + 1];
const int INF = (1 << 30);

int dp(vector<int> coins, int target, int carry) {
    if (carry > target) return INF;
    if (carry == target) return 0;
    if (memo[carry]) return memo[carry];
    int best = INF;
    for (const auto &coin : coins) {
        best = min(best, dp(coins, target, carry + coin) + 1);
    }
    memo[carry] = best;
    return best;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;
        coins[i] = coin;
    }

    int ans = dp(coins, x, 0);
    if (ans == INF) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
