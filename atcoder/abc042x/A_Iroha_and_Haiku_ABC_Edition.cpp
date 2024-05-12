#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    vector<int> haikus(3);
    for (int i = 0; i < 3; i++) {
        cin >> haikus[i];
    }
    sort(haikus.begin(), haikus.end());

    if (haikus[0] == 5 && haikus[1] == 5 && haikus[2] == 7)
        return "YES";
    else
        return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
