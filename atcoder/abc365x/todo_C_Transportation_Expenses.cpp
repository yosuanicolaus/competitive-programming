#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    ll total = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    if (total <= m) return "infinite";

    sort(arr.begin(), arr.end());
    // if (arr[0] * n)

    return 42;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
