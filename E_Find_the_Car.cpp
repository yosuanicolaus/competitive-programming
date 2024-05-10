#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

auto solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<ll> points(k + 1);
    vector<ll> minutes(k + 1);
    vector<ld> speeds(k + 1);

    for (int i = 1; i <= k; i++) {
        cin >> points[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> minutes[i];
    }
    for (int i = 1; i <= k; i++) {
        speeds[i] = (ld)(points[i] - points[i - 1]) / (minutes[i] - minutes[i - 1]);
    }

    for (int i = 0; i < q; i++) {
        ll d;
        cin >> d;
        int id = (int)(lower_bound(points.begin(), points.end(), d) - points.begin());
        if (points[id] == d) {
            cout << minutes[id] << ' ';
        } else {
            cout << minutes[id - 1] + (ll)(speeds[id] * (points[id] - d)) << ' ';
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
