#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[51][51];
string s;

int maxpalin(int a, int b) {
    if (b < a) return 0;
    if (a == b) return 1;
    if (dp[a][b] != -1) return dp[a][b];

    int ans;
    if (s[a] == s[b]) {
        ans = 2 + maxpalin(a + 1, b - 1);
    } else {
        ans = max(maxpalin(a + 1, b), maxpalin(a, b - 1));
    }

    dp[a][b] = ans;
    return ans;
}

auto solve() {
    memset(dp, -1, sizeof(dp));
    cin >> s;
    return maxpalin(0, (int)s.size() - 1);
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
