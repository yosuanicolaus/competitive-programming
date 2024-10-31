#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int xa = min(a, b), xb = max(a, b);
    int xc = min(c, d), xd = max(c, d);

    if ((xc > xa && xd < xb) || (xc < xa && xd > xb) || (xc > xb) || (xd < xa))
        return "NO";
    else
        return "YES";
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
