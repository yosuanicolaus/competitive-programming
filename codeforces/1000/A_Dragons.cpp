#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> dragons(n);

    for (int i = 0; i < n; i++) {
        int dragon, bonus;
        cin >> dragon >> bonus;
        dragons[i] = {dragon, bonus};
    }
    sort(dragons.begin(), dragons.end());

    for (const auto &[dragon, bonus] : dragons) {
        if (s <= dragon) return "NO";
        s += bonus;
    }
    return "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
