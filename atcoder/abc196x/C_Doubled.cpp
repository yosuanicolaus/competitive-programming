#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    ll N;
    cin >> N;
    int ans = 0;

    ll c = 100;
    int i = 9;
    while (N >= c) {
        ans += i;
        c *= 100;
        i = stoi(to_string(i) + '0');
    }

    int len = (int)(to_string(N).size());
    if (len % 2 == 1) return ans;

    len /= 2;
    string z(len - 1, '0');
    int x = stoi("1" + z);
    int n = stoi(to_string(N).substr(0, len));
    int nn = stoi(to_string(N).substr(len));
    ans += n - x + 1;
    if (nn < n) ans--;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
