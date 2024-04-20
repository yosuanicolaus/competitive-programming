#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// not finished yet

// precalc[ fac_count(i) ] = tri_num(i)
int precalc[1002];

int fac_count(int num) {
    int count = 0;
    for (int i = 1; i <= (int)sqrt(num); i++) {
        if (num % i == 0) {
            count++;
            if (num / i != i) count++;
        }
    }
    return count;
}

void precalculate() {
    int found_count = 0;
    for (int i = 1;; i++) {
        int tri_num = i * (i + 1) / 2;
        int ftc = fac_count(tri_num);
        if (ftc <= 1001 && precalc[ftc] == 0) {
            precalc[ftc] = tri_num;
            found_count++;
            if (found_count == 50) break;
        }
    }
}

auto solve() {
    int n;
    cin >> n;
    for (int i = n + 1; i <= 1001; i++) {
        if (precalc[i]) return precalc[i];
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precalculate();
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    dbg(precalc);
    return 0;
}
