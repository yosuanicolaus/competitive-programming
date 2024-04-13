#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define d(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    bool is_same = true;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i > 0 && arr[i] != arr[i - 1]) is_same = false;
    }
    if (is_same) return -1;

    int same = arr[0];
    int same_count = 1;
    int best = n;
    for (int i = 1; i < n; i++) {
        if (arr[i] == same) {
            same_count++;
        } else {
            best = min(best, same_count);
            same_count = 0;
        }
    }
    if (same_count > 0) best = min(best, same_count);

    return best;
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
