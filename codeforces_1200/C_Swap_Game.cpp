#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll a1;
    cin >> a1;
    ll min_a = a1;

    for (int i = 1; i < n; i++) {
        ll other_num;
        cin >> other_num;
        min_a = min(min_a, other_num);
    }
    if (a1 == min_a) {
        cout << "Bob" << '\n';
    } else {
        cout << "Alice" << '\n';
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
