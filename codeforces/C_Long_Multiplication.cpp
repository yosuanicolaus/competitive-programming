#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define d(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    string x, y, big, small;
    cin >> x >> y;
    bool start_divide = false;

    for (int i = 0; i < x.size(); i++) {
        if (start_divide) {
            big += min(x[i], y[i]);
            small += max(x[i], y[i]);
        } else {
            if (x[i] == y[i]) {
                big += x[i];
                small += y[i];
            } else {
                start_divide = true;
                big += max(x[i], y[i]);
                small += min(x[i], y[i]);
            }
        }
    }
    return big + '\n' + small;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
