#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool idxs[3002];

auto solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int idx;
        cin >> idx;
        idxs[idx] = true;
    }

    for (int i = 1; i <= 3001; i++) {
        if (!idxs[i]) return i;
    }
    return 3001;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
