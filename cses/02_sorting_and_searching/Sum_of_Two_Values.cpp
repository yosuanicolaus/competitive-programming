#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> val_pos;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        val_pos.push_back({val, i + 1});
    }
    sort(val_pos.begin(), val_pos.end());

    int a = 0, b = n - 1;
    while (a < b) {
        auto [va, pa] = val_pos[a];
        auto [vb, pb] = val_pos[b];

        if (va + vb == x) {
            ostringstream ss;
            ss << val_pos[a].second << ' ' << val_pos[b].second;
            return ss.str();
        } else if (va + vb < x) {
            a++;
        } else {
            b--;
        }
    }
    return "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
