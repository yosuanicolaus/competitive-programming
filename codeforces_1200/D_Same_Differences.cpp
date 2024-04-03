#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Previously TLE (brute force), then solved with editorial help
// lesson: you can try rewrite the formula, make it more simple
// a[j] - a[i] == j - i
// a[j] - j == a[i] - i
// suppose b[x] = a[x] - x
// b[j] == b[j]
// we can see that now b is also an array
// total of count will always be count of all previous value + the new one

void solve() {
    int n;
    cin >> n;
    map<int, int> b;
    ll res = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x -= i;

        res += b[x];
        b[x]++;
    }
    cout << res << '\n';
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
