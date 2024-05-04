#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Verdict: WA (x40), AC(x11), TLE(x1)
// https://atcoder.jp/contests/abc352/submissions/53136430
// first time doing weighted graphs
// solution: learn DSU and try again in the future
// (great fkin job btw!)

auto solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<vector<int>>> wedgs;
    set<int> visited;

    for (int i = 0; i < m; i++) {
        int k, c;
        cin >> k >> c;
        vector<int> sv(k);
        for (int j = 0; j < k; j++) {
            cin >> sv[j];
            visited.insert(sv[j]);
        }
        wedgs[c].push_back(sv);
    }

    if ((int)visited.size() != n) return -1LL;
    visited.clear();
    ll ans = 0;

    for (auto &[w, wsv] : wedgs) {
        for (auto &sv : wsv) {
            int sz = (int)sv.size();
            for (int i = 0; i < sz; i++) {
                for (int j = i + 1; j < sz; j++) {
                    if (!visited.count(sv[i]) || !visited.count(sv[j])) {
                        visited.insert(sv[i]);
                        visited.insert(sv[j]);
                        ans += w;
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
