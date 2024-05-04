#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int lo = min(x, y), hi = max(x, y);

    if (lo <= z && z <= hi)
        return "Yes";
    else
        return "No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
