#if LOCAL
#include "template/debug.h"
#else
#define d(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    int min_k = 1;

    ll first;
    cin >> first;
    arr[0] = first;
    vector<pair<int, int>> good_idxs;

    for (int i = 1; i < n; i++) {
        ll a;
        cin >> a;
        arr[i] = a;
        if (arr[i - 1] > arr[i]) min_k++;
    }
    if (n == 1) return "Yes";
    if (min_k > k) return "No";

    int l = 0, r = 1;
    while (l < n - 1) {
        if (arr[l] < arr[r]) {
            int good_l = l;
            int good_r = r;
            while (good_r < n && arr[good_r - 1] < arr[good_r]) {
                good_r++;
            }
            good_idxs.push_back({good_l, good_r - 1});
            l = good_r;
            r = l + 1;
        } else {
            l++;
            r++;
        }
    }

    vector<ll> good_arr = arr;
    sort(good_arr.begin(), good_arr.end());
    for (auto [l, r] : good_idxs) {
        while (l < r) {
            auto it = upper_bound(good_arr.begin(), good_arr.end(), arr[l]);
            if (*it != arr[l + 1]) min_k++;
            l++;
        }
    }
    return (min_k <= k) ? "Yes" : "No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
