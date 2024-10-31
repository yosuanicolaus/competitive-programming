#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
    string s;
    cin >> s;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] != s[0]) {
            swap(s[i], s[0]);
            return "YES\n" + s;
        }
    }
    return "NO";
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
