#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    ll a, b;
    cin >> a >> b;
    ll ans = a, c = 2, d = 4;

    while (c <= b && a + c >= d) {
        ans += (a + c) / d;
        c++;
        d = c * c;
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
