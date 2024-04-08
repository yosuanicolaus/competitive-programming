#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    string target = "hello";
    int target_idx = 0;
    int s_idx = 0;

    while (target_idx < 5 && s_idx < s.size()) {
        if (s[s_idx] == target[target_idx]) {
            target_idx++;
        }
        s_idx++;

        if (target_idx == 5) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
