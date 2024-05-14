#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LIMIT = 1e8;

auto solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        ans += nums[i];
    }
    sort(nums.begin(), nums.end());
    ans *= (n - 1);
    ll rmod = 0;

    for (int i = 0; i < n - 1; i++) {
        int j = (int)(lower_bound(nums.begin(), nums.end(), LIMIT - nums[i]) - nums.begin());
        if (j <= i) j = i + 1;
        rmod += n - j;
    }

    ans -= rmod * LIMIT;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
