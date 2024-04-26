#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, x, first_food;
    cin >> n >> x >> first_food;
    int change = 0;
    int lo = first_food, hi = first_food;

    for (int i = 1; i < n; i++) {
        int food;
        cin >> food;
        lo = min(lo, food);
        hi = max(hi, food);
        if (hi - lo > x * 2) {
            change++;
            lo = hi = food;
        }
    }
    return change;
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
