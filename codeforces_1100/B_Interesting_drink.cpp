#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> shops(n);

    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        shops[i] = price;
    }
    sort(shops.begin(), shops.end());

    int days;
    cin >> days;
    for (int i = 0; i < days; i++) {
        ll coin;
        cin >> coin;

        int best_idx = -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (shops[m] <= coin) {
                best_idx = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << best_idx + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
