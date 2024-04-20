#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MODINT = 1'000'000'007;
const int N = 1001;
int dp[N][N];

auto solve() {
    int n;
    cin >> n;
    vector<string> paths(n);

    for (int i = 0; i < n; i++)
        cin >> paths[i];

    if (paths[0][0] == '*') return 0;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (paths[i][j] == '*') continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MODINT;
        }
    }

    return dp[n - 1][n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
