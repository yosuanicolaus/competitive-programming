#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    string s;
    cin >> s;
    unordered_map<char, int> sc;
    for (const auto &ch : s) {
        sc[ch]++;
    }
    vector<int> counts(101);
    for (const auto &[ch, count] : sc) {
        counts[count]++;
    }
    for (int i = 0; i < 101; i++) {
        if (counts[i] != 0 && counts[i] != 2) return "No";
    }
    return "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
