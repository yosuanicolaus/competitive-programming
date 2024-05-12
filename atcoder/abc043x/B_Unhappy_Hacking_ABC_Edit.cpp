#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    string s;
    cin >> s;
    string ans;
    int n = (int)s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == '0' || s[i] == '1')
            ans.push_back(s[i]);
        else if (!ans.empty())
            ans.pop_back();
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
