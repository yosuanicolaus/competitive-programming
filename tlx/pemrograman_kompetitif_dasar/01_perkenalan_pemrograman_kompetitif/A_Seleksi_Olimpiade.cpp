#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, m;
    string focus_id;
    cin >> n >> m >> focus_id;
    vector<tuple<int, int, int, string>> scores(n);
    for (int i = 0; i < n; i++) {
        string user_id;
        int s1, s2, s3;
        cin >> user_id >> s1 >> s2 >> s3;
        scores[i] = {s3, s2, s1, user_id};
    }
    sort(scores.rbegin(), scores.rend());
    for (int i = 0; i < n; i++) {
        string user_id = get<3>(scores[i]);
        if (user_id == focus_id) {
            if (m - i > 0) {
                return "YA";
            } else {
                return "TIDAK";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
