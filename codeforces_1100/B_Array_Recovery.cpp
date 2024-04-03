#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d[i] = x;
    }

    a[0] = d[0];
    for (int i = 1; i < n; i++) {
        if (d[i] == 0) {
            a[i] = a[i - 1];
            continue;
        }
        int num_plus = a[i - 1] + d[i];
        int num_minus = a[i - 1] - d[i];
        if (num_minus >= 0) {
            cout << -1 << endl;
            return;
        }
        a[i] = num_plus;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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
