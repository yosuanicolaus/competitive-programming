#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, t;
    cin >> n >> t;
    vector<int> books(n + 1);
    books[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> books[i];
    }

    int pa = 0, pb = 0;
    int remain = t;
    int max_book = 0;

    while (pa < n && pb <= n) {
        while (pb + 1 <= n && remain >= books[pb + 1]) {
            remain -= books[pb + 1];
            pb++;
        }
        max_book = max(max_book, pb - pa);
        pa++;
        remain += books[pa];
    }

    return max_book;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
