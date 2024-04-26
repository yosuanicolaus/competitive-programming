#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

auto solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_set<int, chash> seen;
    vector<int> psl(n, 0);
    psl[0] = 1;
    seen.insert(a[0]);

    for (int i = 1; i < n; i++) {
        if (seen.count(a[i]))
            psl[i] = psl[i - 1];
        else {
            psl[i] = psl[i - 1] + 1;
            seen.insert(a[i]);
        }
    }
    seen.clear();
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (seen.count(a[i])) continue;
        seen.insert(a[i]);
        ans += psl[i];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
