#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, x;
    cin >> n >> x;
    vector<ll> weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    sort(weights.begin(), weights.end());

    int l = 0, r = n - 1;
    int gondolas = 0;
    while (l < r) {
        if (weights[l] + weights[r] <= x) {
            gondolas++;
            l++;
            r--;
        } else {
            gondolas++;
            r--;
        }
    }
    if (l == r) gondolas++;

    return gondolas;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
