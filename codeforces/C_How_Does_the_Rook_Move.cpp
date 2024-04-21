#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[300001];
const int MODINT = 1000000007;

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

    memo[0] = memo[1] = 1;
    memo[2] = 3;
    for (int i = 3; i <= n; i++) {
        memo[i] = memo[i - 1] + 2 * (i - 1) * memo[i - 2];
        memo[i] %= MODINT;
    }
    return memo[n];
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
