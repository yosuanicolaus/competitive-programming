#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int k, q;
    cin >> k >> q;
    vector<int> ak(k);
    vector<int> nq(q);
    int min_kick = 101;

    for (int i = 0; i < k; i++) {
        cin >> ak[i];
        min_kick = min(min_kick, ak[i]);
    }
    for (int i = 0; i < q; i++) {
        cin >> nq[i];
        cout << min(min_kick - 1, nq[i]) << ' ';
    }
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
