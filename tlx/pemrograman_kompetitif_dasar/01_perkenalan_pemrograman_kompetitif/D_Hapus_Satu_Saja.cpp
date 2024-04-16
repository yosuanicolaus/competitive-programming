#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    string a, b;
    cin >> a >> b;
    int pa = 0, pb = 0;
    int wrong_count = 0;

    if (a.size() - b.size() != 1) return "Wah, tidak bisa :(";

    while (pa < a.size() && pb < b.size()) {
        if (a[pa] != b[pb]) {
            pa++;
            wrong_count++;
            if (wrong_count > 1) return "Wah, tidak bisa :(";
        } else {
            pa++;
            pb++;
        }
    }
    return "Tentu saja bisa!";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
