#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    string s;
    cin >> n >> s;
    ll win = 1;
    vector<bool> wins(n, false);

    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            win++;
            wins[i] = true;
        } else if (i >= 2 && s[i - 2] == s[i] && !wins[i - 1]) {
            win++;
            wins[i] = true;
        }
    }
    return win;
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
