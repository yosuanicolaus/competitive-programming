#include "../template/debug.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> primes = {2};
constexpr int s = 100'001;
array<bool, s> is_prime;
int prime_family[11];

int memo[1'000'000];

int count_family(string digits) {
    int num = stoi(digits);
    if (memo[num] != -1) return memo[num];
    int family = 0;

    for (int i = 1; i < 1 << digits.size(); i++) {
        // todo: generate all subsets
    }

    memo[num] = family;
    return family;
}

int main() {
    memset(memo, -1, sizeof(memo));
    is_prime.fill(true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 4; i < s; i += 2) {
        is_prime[i] = false;
    }
    for (int i = 3; i < s; i++) {
        if (is_prime[i]) {
            for (int j = i * 3; j < s; j += 2 * i) {
                is_prime[j] = false;
            }
            primes.push_back(i);
        }
    }

    for (int prime : primes) {
        string digits = to_string(prime);
        dbg(digits);
    }
}
