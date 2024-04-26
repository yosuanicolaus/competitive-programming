#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    char ans = 'A';
    for (int i = 0; i < 3; i++) {
        bool have_a = false, have_b = false, have_c = false;
        string s;
        cin >> s;
        for (const auto &ch : s) {
            if (ch == 'A')
                have_a = true;
            else if (ch == 'B')
                have_b = true;
            else if (ch == 'C')
                have_c = true;
        }
        if (!have_a) ans = 'A';
        if (!have_b) ans = 'B';
        if (!have_c) ans = 'C';
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
