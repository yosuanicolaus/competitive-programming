#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[300001];
const int MODINT = 1000000007;

ll moves(int n) {
    if (n == 1) return n;
    if (n == 2) return 3;
    if (memo[n] != -1) return memo[n];

    ll ans = moves(n - 1) + (n - 1) * 2 * moves(n - 2);
    ans %= MODINT;
    memo[n] = ans;
    return ans;
}

auto solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b)
            n--;
        else
            n -= 2;
    }

    return moves(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(memo, -1, sizeof(memo));
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
