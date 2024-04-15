#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    string pattern;
    int n;
    cin >> pattern >> n;
    string start = "", end = "";

    int p = 0;
    while (pattern[p] != '*')
        p++;
    start = pattern.substr(0, p);
    end = pattern.substr(p + 1);
    int size_start = start.size(), size_end = end.size();
    int total_size = size_start + size_end;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        if (word.size() < total_size) continue;
        if (word.substr(0, size_start) == start && word.substr(word.size() - size_end) == end) {
            cout << word << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
