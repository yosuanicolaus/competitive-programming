#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// upsolved after contest
// lesson: be more cautious when dealing with floating numbers
// maybe you don't have to use double/ld at all
// you can divide (/) at the end instead

auto solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(k + 1);
    vector<ll> b(k + 1);

    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];

    for (int i = 0; i < q; i++) {
        ll d;
        cin >> d;
        int id = (int)(lower_bound(a.begin(), a.end(), d) - a.begin());
        if (a[id] == d) {
            cout << b[id] << ' ';
        } else {
            cout << b[id - 1] + (d - a[id - 1]) * (b[id] - b[id - 1]) / (a[id] - a[id - 1]) << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
