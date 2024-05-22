#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<bool> seen(n + 1, false);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (seen[x]) return "No";
        seen[x] = true;
    }

    return "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
