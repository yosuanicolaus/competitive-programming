#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> super_luckies;

void precalc() {
    bitset<8> luck;
    for (const auto &i : {2, 4, 6, 8}) {
        for (int j = 0; j < 1 << i; j++) {
            luck = j;
            if (luck.count() == (size_t)i / 2) {
                string s;
                for (int x = 0; x < i; x++) {
                    s += luck[x] ? '4' : '7';
                }
                super_luckies.push_back(stoi(s));
            }
        }
    }
    sort(super_luckies.begin(), super_luckies.end());
    super_luckies.push_back(4444477777);
}

auto solve() {
    int n;
    cin >> n;
    return *lower_bound(super_luckies.begin(), super_luckies.end(), n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    cout << solve() << '\n';
    return 0;
}
