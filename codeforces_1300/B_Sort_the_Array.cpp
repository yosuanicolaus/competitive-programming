#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
    }

    int swap_l = -1, swap_r = -1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            swap_l = i - 1;
            break;
        }
    }
    if (swap_l == -1) {
        cout << "yes\n1 1\n";
        return;
    }
    for (int i = swap_l + 1; i < n; i++) {
        if (a[i - 1] < a[i]) {
            swap_r = i - 1;
            break;
        }
    }
    if (swap_r == -1) swap_r = n - 1;
    int l = swap_l, r = swap_r;
    while (l < r) {
        swap(a[l], a[r]);
        l++;
        r--;
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            cout << "no" << '\n';
            return;
        }
    }
    cout << "yes" << '\n';
    cout << swap_l + 1 << " " << swap_r + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
