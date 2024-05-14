#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, k;
    cin >> n >> k;
    int carry = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int g;
        cin >> g;
        if (carry + g > k) {
            carry = 0;
            ans++;
        }
        carry += g;
    }

    if (carry > 0) ans++;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
