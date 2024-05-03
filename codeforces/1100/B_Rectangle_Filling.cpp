#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, m;
    cin >> n >> m;
    bool wt, wb, wl, wr, bt, bb, bl, br;
    wt = wb = wl = wr = bt = bb = bl = br = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char sq;
            cin >> sq;
            if (sq == 'W') {
                if (i == 0) wt = true;
                if (j == 0) wl = true;
                if (i == n - 1) wb = true;
                if (j == m - 1) wr = true;
            } else {
                if (i == 0) bt = true;
                if (j == 0) bl = true;
                if (i == n - 1) bb = true;
                if (j == m - 1) br = true;
            }
        }
    }

    if ((wt && wl && wb && wr) || (bt && bl && bb && br))
        return "YES";
    else
        return "NO";
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
