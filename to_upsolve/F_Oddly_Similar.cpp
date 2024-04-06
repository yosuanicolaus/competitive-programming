#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// TLE ...?

bool is_similar(vector<int> a, vector<int> b, int len) {
    int similar_count = 0;

    for (int i = 0; i < len; i++) {
        if (a[i] == b[i]) {
            similar_count++;
        }
    }
    return (similar_count % 2 == 1);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n);

    for (int i = 0; i < n; i++) {
        grid[i].resize(m);
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            grid[i][j] = a;
        }
    }

    int similar_count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (is_similar(grid[i], grid[j], m)) similar_count++;
        }
    }
    cout << similar_count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
