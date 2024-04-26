#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int c1 = 0;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) c1++;
        sum += a[i];
    }
    if (n == 1) return "NO";

    int cn = n - c1;
    ll rem = sum - c1 * 2;
    if (rem >= cn) return "YES";
    return "NO";
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
