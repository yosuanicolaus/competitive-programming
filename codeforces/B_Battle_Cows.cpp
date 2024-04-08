#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll my_cow_power = -1;

    for (int i = 0; i < n; i++) {
        ll power;
        cin >> power;
        a[i] = power;
        if (i == k - 1) my_cow_power = power;
    }

    int first_strong_cow_idx = -1;
    for (int i = 0; i < k - 1; i++) {
        if (a[i] > my_cow_power) {
            first_strong_cow_idx = i;
            break;
        }
    }

    // simulate if we swap to start
    swap(a[0], a[k - 1]);
    int win_start = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < my_cow_power)
            win_start++;
        else
            break;
    }
    swap(a[0], a[k - 1]);

    // simulate if we swap to first strong cow
    int win_swap = 0;
    if (first_strong_cow_idx != -1) {
        swap(a[k - 1], a[first_strong_cow_idx]);
        if (first_strong_cow_idx > 0) win_swap = 1;
        for (int i = first_strong_cow_idx + 1; i < n; i++) {
            if (a[i] < my_cow_power)
                win_swap++;
            else
                break;
        }
        swap(a[k - 1], a[first_strong_cow_idx]);
    }

    cout << max(win_start, win_swap) << '\n';
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
