#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    string s;
    cin >> s;
    size_t n = s.size();
    unordered_set<string> seen;
    int count = 0;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i; j < n; j++) {
            string subs = s.substr(i, j - i + 1);
            if (seen.count(subs)) continue;
            count++;
            seen.insert(subs);
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
