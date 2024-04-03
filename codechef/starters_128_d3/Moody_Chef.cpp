#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    int high = 0, low = 0;
    int happiness = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= l && x <= r) {
            happiness++;
            high = max(high, happiness);
        } else {
            happiness--;
            low = min(low, happiness);
        }
    }

    cout << high << " " << low << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
