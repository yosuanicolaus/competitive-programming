#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c == 1)
            c1++;
        else
            c2++;
    }

    if (c2 % 2 == 1) c1 -= 2;
    if (c1 < 0 || c1 % 2 == 1) return "NO";
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
