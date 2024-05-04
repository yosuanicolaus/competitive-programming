#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> giants;
    int best = 0;

    for (int i = 0; i < n; i++) {
        int shoulder, head;
        cin >> shoulder >> head;
        int bonus = head - shoulder;
        best = max(best, bonus);
        giants.push_back({shoulder, head});
    }

    bool found_best = false;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto [shoulder, head] = giants[i];
        if (head - shoulder == best && !found_best) {
            found_best = true;
            ans += head;
            continue;
        }
        ans += shoulder;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
