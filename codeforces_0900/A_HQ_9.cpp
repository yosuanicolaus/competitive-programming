#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string line;
    cin >> line;

    for (const auto &ch : line) {
        if (ch == 'H' || ch == 'Q' || ch == '9') {
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
