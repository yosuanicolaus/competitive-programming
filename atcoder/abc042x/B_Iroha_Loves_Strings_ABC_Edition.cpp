#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, l;
    cin >> n >> l;
    vector<string> vs(n);
    for (int i = 0; i < n; i++) {
        cin >> vs[i];
    }
    sort(vs.begin(), vs.end());
    string ans;
    for (const auto &s : vs) {
        ans += s;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
