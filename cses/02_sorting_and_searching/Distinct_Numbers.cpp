#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int distinct = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) distinct++;
    }
    return distinct;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
