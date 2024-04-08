#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

array<int, 4001> memo;

int dp(int n, int a, int b, int c) {
    if (n < 0) return -4001;
    if (memo[n]) return memo[n];
    if (n == 0) return 0;

    int cut_a = dp(n - a, a, b, c) + 1;
    int cut_b = dp(n - b, a, b, c) + 1;
    int cut_c = dp(n - c, a, b, c) + 1;
    int max_pieces = max(cut_a, max(cut_b, cut_c));

    memo[n] = max_pieces;
    return max_pieces;
}

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << dp(n, a, b, c) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
