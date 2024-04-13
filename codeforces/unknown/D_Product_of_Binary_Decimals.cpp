#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> divisor = {10};

void prefill_divisor() {
    for (int i = 2; i < pow(2, 6); i++) {
        bitset<6> bits(i);
        int bit_digits = stoi(bits.to_string());
        if (bit_digits % 10 != 0) divisor.push_back(bit_digits);
    }
}

bool dp(int n) {
    if (n == 0) return false;
    if (n == 1) return true;

    for (const auto &d : divisor) {
        if (n < d) break;
        if (n % d == 0) {
            bool res = dp(n / d);
            if (res) return res;
        }
    }

    return false;
}

void solve() {
    int n;
    cin >> n;
    if (dp(n)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prefill_divisor();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
