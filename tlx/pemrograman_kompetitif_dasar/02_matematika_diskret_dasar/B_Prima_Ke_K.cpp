#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> primes;

void sieve() {
    const int size = 1000001;
    array<bool, size> is_prime;
    is_prime.fill(true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < size; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j < size; j += i) {
                is_prime[j] = false;
            }
            primes.push_back(i);
        }
    }
}

auto solve() {
    int n;
    cin >> n;
    return primes[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
