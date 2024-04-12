#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define d(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int most_color_count = n / m;
    if (n % m > 0) most_color_count++;
    int need_min_k = n - most_color_count;
    if (need_min_k > k)
        return "YES";
    else
        return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
