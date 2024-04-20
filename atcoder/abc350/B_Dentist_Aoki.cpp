#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, q;
    cin >> n >> q;
    vector<bool> teeth(n, true);
    for (int i = 0; i < q; i++) {
        int tooth;
        cin >> tooth;
        teeth[tooth - 1] = !teeth[tooth - 1];
    }
    int ct = 0;
    for (const auto &tooth : teeth) {
        if (tooth) ct++;
    }
    return ct;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
