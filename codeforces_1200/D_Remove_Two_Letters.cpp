#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int duplicate = 0;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == s[i + 2]) duplicate++;
    }
    cout << n - 1 - duplicate << '\n';
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
