#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    if (n == 1) return 1LL;
    sort(a.begin(), a.end());
    int g = a[1] - a[0];
    for (int i = 2; i < n; i++) {
        g = gcd(g, a[i] - a[i - 1]);
        if (g == 1) break;
    }

    // get closest insert point to the max point
    int ins = n - 2;
    while (ins >= 0 && a[ins] + g == a[ins + 1]) {
        ins--;
    }
    ll ans = n - 1 - ins;
    ll target = a[n - 1];

    for (int i = 0; i < n; i++) {
        ans += (target - a[i]) / g;
    }
    return ans;
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
