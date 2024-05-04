#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    string s, t;
    cin >> s >> t;

    int is = 0, it = 0;
    int n = (int)s.size();

    while (is < n) {
        if (s[is] == t[it]) {
            cout << it + 1 << ' ';
            is++;
        }
        it++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
