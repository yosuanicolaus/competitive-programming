#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> dir(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dir[i] = {a[i], i + 1};
    }

    sort(dir.begin(), dir.end());
    vector<pair<int, int>> opr;

    for (auto [num, idx] : dir) {
        while (num > idx) {
            idx = dir[idx - 1].second;
        }
        if (num == idx) continue;
        opr.push_back({num, idx});
    }

    cout << opr.size() << '\n';
    for (auto [num, idx] : opr) {
        cout << num << ' ' << idx << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
