#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1 << 30;
int dp[50001];

// recursive approach, 1st submission
int min_coins(vector<int> &coins, int remain) {
    if (remain < 0) return INF;
    if (remain == 0) return 0;
    if (dp[remain] != -1) return dp[remain];

    int best = INF;
    for (auto coin : coins) {
        best = min(best, 1 + min_coins(coins, remain - coin));
    }

    dp[remain] = best;
    return best;
}

auto solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> coins(n);
    int target;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cin >> target;

    // i-te-ra-ti-vuh!! approach ^^
    dp[0] = 0;
    for (int i = 1; i <= target; i++) {
        int best = INF;
        for (auto coin : coins) {
            if (i - coin >= 0) best = min(best, 1 + dp[i - coin]);
        }
        dp[i] = best;
    }

    if (dp[target] == INF) dp[target] = -1;
    return dp[target];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
