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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int f = a[0];
    if (f > 1) return "Alice";
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] <= 1) continue;
        int last = a[i - 1];
        if (last % 2 == 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }

    if (a[n - 1] % 2 == 1)
        return "Alice";
    else
        return "Bob";
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
