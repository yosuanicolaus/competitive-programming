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
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        arr[i] = a;
    }

    int l = 0, r = n - 1;
    int sink_count = 0;
    while (k > 0 && l < r) {
        ll a = arr[l], b = arr[r];

        if (a < b) {
            if (k >= a * 2 - 1) sink_count++;
            arr[r] -= a;
            k -= a * 2;
            l++;
        } else { // (a >= b)
            if (k >= b * 2) sink_count++;
            arr[l] -= b;
            k -= b * 2;
            r--;
            if (arr[l] == 0 && k >= -1) {
                sink_count++;
                l++;
            }
        }
    }

    if (l == r && sink_count < n && k >= arr[l]) sink_count++;

    std::cout << sink_count << '\n';
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
