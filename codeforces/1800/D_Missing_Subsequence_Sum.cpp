#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans;

    int i = 1;
    int m = 1;
    while (i < 1000000) {
        if (!(i <= k && i << 1 > k)) {
            ans.push_back(i);
        } else {
            m = i;
        }
        i <<= 1;
    }

    // replace 2^i with the following
    ans.push_back(k - m);     // for 2^(i-1) + 1 .. k - 1
    ans.push_back(k + 1);     // for k + 1 .. 2^(i+1) - 1
    ans.push_back(k + 1 + m); // for all 2^j + k, where j > i

    cout << ans.size() << '\n';
    for (size_t j = 0; j < ans.size(); j++) {
        cout << ans[j] << " \n"[j + 1 == ans.size()];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
