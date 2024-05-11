#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// solved with help of editorial
// ... and ... 3 hours of banging my head on the table
// trying to understand why it works

const ll INF = 1e18;

auto solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            ll mn = INF;
            for (ll d = 0; i + d + 1 <= n && j + d <= k; d++) {
                mn = min(mn, a[i + d]);
                dp[i + d + 1][j + d] = min(dp[i + d + 1][j + d], dp[i][j] + ((d + 1) * mn));
            }
        }
    }
    return *min_element(dp[n].begin(), dp[n].end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
