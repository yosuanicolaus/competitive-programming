#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    vector<double> farthest_dists(n);
    vector<int> farthest_ids(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            // compare point i & j distance
            double dist = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
            if (farthest_dists[i] < dist) {
                farthest_dists[i] = dist;
                farthest_ids[i] = j + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << farthest_ids[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
