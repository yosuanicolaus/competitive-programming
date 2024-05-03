#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<vector<int>> cnt(11, vector<int>(11));
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int cs1 = s[0] - 'a';
        int cs2 = s[1] - 'a';

        for (int y = 0; y < 11; y++) {
            for (int x = 0; x < 11; x++) {
                if ((cs1 == y && cs2 != x) || (cs1 != y && cs2 == x)) {
                    ans += cnt[y][x];
                }
            }
        }
        cnt[cs1][cs2]++;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
