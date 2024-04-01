from math import ceil


# WA on test case 5


# https://stackoverflow.com/questions/2068372/fastest-way-to-list-all-primes-below-n
def primes(n):
    """Returns  a list of primes < n"""
    sieve = [True] * n
    for i in range(3, int(n**0.5) + 1, 2):
        if sieve[i]:
            sieve[i * i :: 2 * i] = [False] * ((n - i * i - 1) // (2 * i) + 1)
    return [2] + [i for i in range(3, n, 2) if sieve[i]]


def solve():
    k = int(input())
    ans = [k]
    best_ans = [k]

    for prime_num in primes(ceil(k**0.5)):
        while ans[-1] % prime_num == 0 and (ans[-1] // prime_num) % prime_num == 0:
            prev = ans.pop()
            ans.extend((prime_num, prev // prime_num))
        if len(ans) > len(best_ans):
            best_ans = ans
        ans = [k]

    return best_ans


def main():
    t = int(input())
    for _ in range(t):
        ans = solve()
        print(len(ans))
        print(" ".join(map(str, ans)))


if __name__ == "__main__":
    main()
