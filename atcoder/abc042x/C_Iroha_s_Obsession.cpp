#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, k;
    cin >> n >> k;
    vector<int> usable;
    vector<bool> disliked(k, false);

    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        disliked[d] = true;
    }
    if (k == 0) return n;
    for (int i = 0; i <= 9; i++) {
        if (!disliked[i]) usable.push_back(i);
    }

    string sn = "0" + to_string(n);
    vector<int> via;
    for (const auto &digit : sn) {
        via.push_back(digit - '0');
    }
    int vs = (int)via.size();
    auto lowest = lower_bound(usable.begin(), usable.end(), 0);

    for (int i = 1; i < vs; i++) {
        if (disliked[via[i]]) {
            auto it = lower_bound(usable.begin(), usable.end(), via[i] + 1);
            if (it != usable.end()) {
                via[i] = *it;
                for (int y = i + 1; y < vs; y++) {
                    via[y] = *lowest;
                }
            } else {
                int x = 0;
                auto jit = usable.end();
                while (jit == usable.end()) {
                    x++;
                    jit = lower_bound(usable.begin(), usable.end(), via[i - x] + 1);
                }
                via[i - x] = *jit;
                for (int y = i - x + 1; y < vs; y++) {
                    via[y] = *lowest;
                }
            }
            break;
        }
    }

    string ans;
    for (const auto &ia : via) {
        ans += (char)(ia + '0');
    }
    return stoi(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
