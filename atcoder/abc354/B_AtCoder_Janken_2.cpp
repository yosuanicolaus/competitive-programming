#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<string> vs(n);
    int sumrating = 0;

    for (int i = 0; i < n; i++) {
        string username;
        int rating;
        cin >> username >> rating;
        vs[i] = username;
        sumrating += rating;
    }
    sort(vs.begin(), vs.end());
    int msr = sumrating % n;
    return vs[msr];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
