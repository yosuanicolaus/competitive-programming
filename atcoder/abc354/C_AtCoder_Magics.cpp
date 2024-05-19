#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> cpi(n);
    for (int i = 0; i < n; i++) {
        int c, p;
        cin >> p >> c;
        cpi[i] = {c, p, i + 1};
    }
    sort(cpi.begin(), cpi.end());
    int min_power = 0;
    vector<int> ans;
    for (const auto &[c, p, i] : cpi) {
        if (p > min_power) {
            min_power = p;
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (const auto &id : ans) {
        cout << id << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
