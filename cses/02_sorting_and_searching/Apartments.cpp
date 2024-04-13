#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> applicants(n), apartments(m);

    for (int i = 0; i < n; i++)
        cin >> applicants[i];
    for (int i = 0; i < m; i++)
        cin >> apartments[i];
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int success = 0;
    int pa = 0, pb = 0;
    while (pa < n && pb < m) {
        if (abs(applicants[pa] - apartments[pb]) <= k) {
            success++;
            pa++;
            pb++;
        } else if (applicants[pa] > apartments[pb]) {
            pb++;
        } else {
            pa++;
        }
    }
    return success;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
