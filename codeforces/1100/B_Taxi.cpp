#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> counts(5); // use idx 1-4

    for (int i = 0; i < n; i++) {
        int group;
        cin >> group;
        counts[group]++;
    }

    ll ans = counts[4];
    ans += counts[3];
    counts[1] -= counts[3];
    ans += counts[2] / 2;
    ll remain = 0;

    if (counts[2] % 2 == 1) remain += 2;
    if (counts[1] > 0) remain += counts[1];

    ans += remain / 4;
    if (remain % 4 > 0) ans++;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
