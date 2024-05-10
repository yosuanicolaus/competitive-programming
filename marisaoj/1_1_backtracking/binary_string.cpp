#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> ans;

void print_ans() {
    for (int i = 0; i < n; i++)
        cout << ans[i];
    cout << '\n';
}

void backtrack(int idx) {
    if (idx == n) return print_ans();
    ans[idx] = 1;
    backtrack(idx + 1);
    ans[idx] = 0;
    backtrack(idx + 1);
}

auto solve() {
    cin >> n;
    ans.resize(n);
    backtrack(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
