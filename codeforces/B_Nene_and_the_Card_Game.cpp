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
    unordered_set<int> seen;
    int dup_count = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (seen.count(a)) dup_count++;
        seen.insert(a);
    }
    return dup_count;
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
