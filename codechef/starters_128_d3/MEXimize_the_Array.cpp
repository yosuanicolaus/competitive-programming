#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> nums(n);

    for (ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        nums[i] = num;
    }

    sort(nums.begin(), nums.end());
    ll opr = 0;

    for (ll i = 0; i < n; i++) {
        opr += abs(nums[i] - i);
    }

    cout << opr << endl;
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
