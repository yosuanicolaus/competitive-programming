#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    ll ia = stoll(a);
    ll ib = stoll(b);
    ll ic = ia + ib;
    string ans = to_string(ic);
    reverse(ans.begin(), ans.end());
    ll ians = stoll(ans);
    return ians;
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
