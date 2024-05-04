#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, k;
    cin >> n >> k;
    vector<int> idxs(n + 1);
    set<int> sid;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        idxs[num] = i;
        if (num <= k) sid.insert(i);
    }
    if (k == 1) return 0;

    int best = *sid.rbegin() - *sid.begin();
    int a = 2, b = k + 1;
    while (b <= n) {
        sid.erase(idxs[a - 1]);
        sid.insert(idxs[b]);
        int newmin = *sid.rbegin() - *sid.begin();
        best = min(best, newmin);
        a++;
        b++;
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
