#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> days(n);
    int total = a + b;

    for (int i = 0; i < n; i++) {
        cin >> days[i];
        days[i] %= total;
    }
    sort(days.begin(), days.end());
    if (days[n - 1] - days[0] + 1 <= a) return "Yes";

    int hidist = -1, hiidx = -1;
    for (int i = 0; i + 1 < n; i++) {
        if (days[i + 1] - days[i] > hidist) {
            hidist = days[i + 1] - days[i];
            hiidx = i;
        }
    }
    for (int i = 0; i <= hiidx; i++) {
        days[i] += total;
    }

    int small = days[hiidx + 1], big = days[hiidx];
    if (big - small + 1 <= a)
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
