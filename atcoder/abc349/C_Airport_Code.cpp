#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    string s, t;
    cin >> s >> t;
    int ps = 0, pt = 0;
    while (ps < s.size() && pt < 3) {
        if (toupper(s[ps]) == t[pt]) {
            ps++;
            pt++;
        } else {
            ps++;
        }
    }
    if ((pt == 2 && t[2] == 'X') || pt == 3) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
