#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    int l = 0, r = 1;
    ll ans = 0;

    while (l < n && r < n) {
        if (s[l] == '0') {
            l++;
        } else {
            if (r <= l)
                r = l + 1;
            else if (s[r] == '1')
                r++;
            else {
                // s[r] == '0' -> do swap
                s[l] = '0';
                s[r] = '1';
                ans += r - l + 1;
                l++;
                r++;
            }
        }
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
