#if LOCAL
#include "template/debug.h"
#else
#define d(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = (int)1e9 + 7;

ll memo[1000001];

ll dp(int target, int current) {
    if (current > target) return 0;
    if (current == target) return 1;
    if (memo[current]) return memo[current];

    ll ways = 0;
    for (int i = 1; i <= 6; i++)
        ways += dp(target, current + i);
    ways %= M;

    memo[current] = ways;
    return ways;
}

void solve() {
    int n;
    cin >> n;
    cout << dp(n, 0) % M << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 1000001; i++)
        memo[i] = 0;
    solve();
    return 0;
}
