#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    string s;
    cin >> n >> s;

    int c0 = 0, c1 = 0;
    for (const auto &ch : s) {
        if (ch == '0')
            c0++;
        else
            c1++;
    }
    if (c0 != c1) {
        cout << -1 << '\n';
        return;
    }

    vector<int> ans;
    deque<char> q;
    for (const auto &ch : s) {
        q.push_back(ch);
    }

    int d = 0;
    while (!q.empty()) {
        if (q.front() == q.back()) {
            if (q.front() == '0') {
                q.pop_front();
                q.push_back('0');
                ans.push_back(n - d);
            } else {
                q.pop_back();
                q.push_front('1');
                ans.push_back(d);
            }
            n += 2;
            d++;
        }

        while (!q.empty() && q.front() != q.back()) {
            q.pop_front();
            q.pop_back();
            d++;
        }
    }

    cout << ans.size() << '\n';
    for (const auto &x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
