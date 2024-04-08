#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    vector<ll> arr(n * n);
    unordered_map<ll, int> progressives;
    ll min_num = INT32_MAX;

    for (int i = 0; i < n * n; i++) {
        ll a;
        cin >> a;
        arr[i] = a;
        min_num = min(min_num, a);
    }

    ll num = min_num;

    for (int i = 0; i < n; i++) {
        ll row_num = num;
        progressives[num]++;
        for (int j = 1; j < n; j++) {
            num += d;
            progressives[num]++;
        }
        num = row_num + c;
    }

    bool is_yes = true;
    for (int i = 0; i < n * n; i++) {
        progressives[arr[i]]--;
        if (progressives[arr[i]] < 0) {
            is_yes = false;
            break;
        }
    }

    if (is_yes)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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
