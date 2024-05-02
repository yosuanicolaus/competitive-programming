#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    ll best = -1e9;
    ll curr = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        curr += x;
        best = max(best, curr);
        if (curr < 0) curr = 0;
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
