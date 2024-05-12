#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

auto solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += 100;
        sum += a[i];
    }

    ld med = (ld)sum / n;
    int rmed = (int)round(med);
    int cost = 0;
    for (const auto &ai : a) {
        int xi = abs(ai - rmed);
        cost += xi * xi;
    }

    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
