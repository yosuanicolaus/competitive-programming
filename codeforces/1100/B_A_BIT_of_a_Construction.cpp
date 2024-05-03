#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << '\n';
        return;
    }

    int i = 1, ni = 3, x = 3;
    while (ni <= k) {
        i = ni;
        ni = 1;
        for (int y = 0; y < x; y++) {
            ni *= 2;
        }
        ni--;
        x++;
    }

    int remain = k - i;

    for (int j = 0; j < n; j++) {
        if (j == 0)
            cout << i << ' ';
        else {
            cout << remain << " \n"[j == n - 1];
            remain = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
