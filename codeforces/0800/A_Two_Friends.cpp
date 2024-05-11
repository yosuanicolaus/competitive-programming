#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    bool have_cycle = false;
    for (int i = 1; i <= n; i++) {
        if (p[p[i]] == i) {
            have_cycle = true;
            break;
        }
    }
    if (have_cycle)
        return 2;
    else
        return 3;
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
