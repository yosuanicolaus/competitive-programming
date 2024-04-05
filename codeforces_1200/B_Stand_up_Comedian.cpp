#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll s, a, b, c;
    cin >> s >> a >> b >> c;

    ll jokes = s;
    ll life = s;

    if (life > 0) {
        jokes += min(a, b) * 2;
        ll remains = max(a, b) - min(a, b) + c;
        if (life >= remains)
            jokes += remains;
        else
            jokes += life + 1;
    } else if (a > 0 || b > 0 || c > 0) {
        jokes = 1;
    }
    cout << jokes << '\n';
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
