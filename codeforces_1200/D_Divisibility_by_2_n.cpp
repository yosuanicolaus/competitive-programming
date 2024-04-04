#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int our_n = 0;

    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        while (num % 2 == 0) {
            our_n++;
            num /= 2;
        }
    }

    if (our_n >= n) {
        cout << 0 << '\n';
        return;
    }

    vector<int> n_increments;
    for (int i = 1; i <= n; i++) {
        int c = 0;
        int ci = i;
        while (ci % 2 == 0) {
            c++;
            ci /= 2;
        }
        if (c > 0) n_increments.push_back(c);
    }
    sort(n_increments.begin(), n_increments.end());

    int operation = 0;
    while (our_n < n && !n_increments.empty()) {
        our_n += n_increments.back();
        n_increments.pop_back();
        operation++;
    }

    if (our_n >= n) {
        cout << operation << '\n';
    } else {
        cout << -1 << '\n';
    }
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
