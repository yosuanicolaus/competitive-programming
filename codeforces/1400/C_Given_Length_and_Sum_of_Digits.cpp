#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void base_case() {
    cout << "-1 -1" << '\n';
}

auto solve() {
    int m, s;
    cin >> m >> s;
    string ans;
    if (s == 0) {
        if (m > 1)
            return base_case();
        else {
            cout << "0 0" << '\n';
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        ans += "01"[i == 0];
    }

    s--;
    int pm = m - 1;
    while (s > 0 && pm >= 0) {
        if (s > 9) {
            ans[pm] = '9';
            s -= 9;
        } else {
            if (pm == 0) s++;
            if (s > 9) return base_case();
            ans[pm] = static_cast<char>((s) + '0');
            s = 0;
        }
        pm--;
    }
    if (s > 0) return base_case();

    string ans2 = ans;
    reverse(ans2.begin(), ans2.end());
    if (ans2[m - 1] == '1') {
        for (int i = 0; i < m - 1; i++) {
            if (ans2[i] < '9') {
                // ans2[i] = static_cast<char>((ans2[i] -) )
                int d = ans2[i] - '0';
                d++;
                ans2[i] = static_cast<char>(d + '0');
                ans2[m - 1] = '0';
                break;
            }
        }
    }
    cout << ans << ' ' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
