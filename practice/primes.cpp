#include <bits/stdc++.h>
using LL = long long;

std::vector<int> primes;

std::vector<int> generate_primes(int limit) {
    std::vector<bool> is_prime(limit + 1, true);
    std::vector<int> primes;
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= limit; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= limit; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}

bool is_coprime(int num1, int num2) {
    int a = std::min(num1, num2);
    int b = std::max(num1, num2);
    if (a == b && a != 1) {
        return false;
    }

    for (int i = 0; i < primes.size(); i++) {
        int prime_num = primes[i];
        if (prime_num > a) {
            break;
        }
        if (a % prime_num == 0 && b % prime_num == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    primes = generate_primes(10);
    for (auto &num : primes) {
        std::cout << num << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
