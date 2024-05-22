#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    unordered_map<int, int> cnt;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        cnt[a[i]]++;
        ans += n - i - cnt[a[i]];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
