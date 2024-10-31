#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    string s;
    cin >> s;
    int pieces = 1;
    char last = s[0];

    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] != last) {
            pieces++;
            last = s[i];
        }
    }

    if (pieces >= 3 || (pieces == 2 && s[0] == '0')) pieces--;
    return pieces;
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
