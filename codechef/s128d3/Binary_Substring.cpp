#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    ll c10 = 0, c01 = 0, c00 = 0, c11 = 0;
    for (ll i = 0; i < n - 1; i += 2) {
        if (s[i] == '0') {
            if (s[i + 1] == '0')
                c00++;
            else
                c01++;
        } else {
            if (s[i + 1] == '0')
                c10++;
            else
                c11++;
        }
    }

    ll ans = 0;
    if (c10 > 0) {
        ans++;
        c10--;
    }
    ans += 2 * c00;
    if (c01 > 0) {
        ans += 2;
        c01--;
    }
    ans += 2 * c11;
    if (c10 > 0) {
        ans++;
        c10--;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
