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
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll x;
    cin >> x;

    ll ans = x / sum * n;
    ll r = x % sum;
    ll b = 0;
    int i = 0;

    while (b <= r) {
        b += a[i];
        i++;
    }
    ans += i;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
