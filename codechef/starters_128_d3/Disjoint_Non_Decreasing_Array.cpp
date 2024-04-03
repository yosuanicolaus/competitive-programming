#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> nums(n);

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        nums[i] = x;
    }

    for (ll i = 1; i < n; i++) {
        if (nums[i - 1] > nums[i]) {
            // do the check here
            ll last_dec_idx = i;
            ll minpath = nums[i - 1] - nums[i];
            ll maxpath = (i + 1 < n) ? nums[i + 1] - nums[i] : pow(10, 9) + 1;
            if (maxpath < minpath) {
                cout << "No" << endl;
                return;
            }

            for (ll j = i + 1; j < n; j++) {
                if (nums[j - 1] > nums[j]) {
                    if (j - last_dec_idx == 1) {
                        cout << "No" << endl;
                        return;
                    }
                    ll new_minpath = nums[j - 1] - nums[j];
                    ll new_maxpath =
                        (j + 1 < n) ? nums[j + 1] - nums[j] : pow(10, 9) + 1;
                    if (new_maxpath < new_minpath || new_minpath > maxpath ||
                        new_maxpath < minpath) {
                        cout << "No" << endl;
                        return;
                    }
                    minpath = max(minpath, new_minpath);
                    maxpath = min(maxpath, new_maxpath);
                }
            }
            break;
        }
    }
    cout << "Yes" << endl;
    return;
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
