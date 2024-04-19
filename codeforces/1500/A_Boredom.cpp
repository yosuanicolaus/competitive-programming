#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100'001;
ll vals[N];
ll dp[N];

auto solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vals[num] += num;
    }

    dp[0] = 0;
    dp[1] = vals[1];
    dp[2] = vals[2];
    for (int i = 3; i < N; i++) {
        dp[i] = vals[i] + max(dp[i - 2], dp[i - 3]);
    }
    return max(dp[N - 2], dp[N - 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
