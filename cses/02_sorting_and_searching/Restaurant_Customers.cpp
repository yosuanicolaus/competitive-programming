#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        times.push_back({a, 1});
        times.push_back({b, -1});
    }

    sort(times.begin(), times.end());
    int curr = 0;
    int best = 0;
    for (const auto &[a, b] : times) {
        curr += b;
        best = max(best, curr);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
