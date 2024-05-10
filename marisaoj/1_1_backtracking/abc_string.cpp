#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<char> abc;
string ABC = "ABC";

void backtrack(int idx) {
    if (idx == n) {
        for (int i = 0; i < n; i++) {
            cout << abc[i];
        }
        cout << '\n';
        return;
    }

    for (const auto &ch : ABC) {
        if (idx == 0 || abc[idx - 1] != ch) {
            abc[idx] = ch;
            backtrack(idx + 1);
        }
    }
}

auto solve() {
    cin >> n;
    abc.resize(n);
    backtrack(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
