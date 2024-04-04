#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> pfs(n + 1);
    pfs[0] = 0;

    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;
        pfs[i] = pfs[i - 1] + height;
    }

    int min_idx = 1;
    int min_height = pfs[k];
    for (int i = k + 1; i <= n; i++) {
        int sum_height = pfs[i] - pfs[i - k];
        if (sum_height < min_height) {
            min_height = sum_height;
            min_idx = i - k + 1;
        }
    }
    cout << min_idx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
