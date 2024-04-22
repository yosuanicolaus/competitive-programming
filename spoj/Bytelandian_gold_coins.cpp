#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> dp;

ll maxtrade(ll coin) {
    if (coin == 0) return 0;
    if (dp[coin]) return dp[coin];
    ll ans = max(coin, maxtrade(coin / 2) + maxtrade(coin / 3) + maxtrade(coin / 4));
    dp[coin] = ans;
    return ans;
}

auto solve() {
    int n;
    while (cin >> n) {
        cout << maxtrade(n) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
