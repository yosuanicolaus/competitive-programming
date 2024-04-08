#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> t_primes;

void fill_t_primes() {
    // get all prime from 1 - 10**6
    // then fill t_primes with all T-prime from 1 - 10**12
    constexpr ll limit = 1000001;
    array<bool, limit> is_prime;

    is_prime.fill(true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (ll i = 2; i < limit; i++) {
        if (is_prime[i] == false) continue;
        for (ll j = i * i; j < limit; j += i) {
            is_prime[j] = false;
        }
    }

    for (ll i = 2; i < limit; i++) {
        if (is_prime[i]) t_primes.push_back(i * i);
    }
}

void solve() {
    ll x;
    cin >> x;

    if (binary_search(t_primes.begin(), t_primes.end(), x)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fill_t_primes();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
