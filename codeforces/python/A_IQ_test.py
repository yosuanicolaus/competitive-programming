def primes(n):
    """Returns  a list of primes < n"""
    sieve = [True] * n
    for i in range(3, int(n**0.5) + 1, 2):
        if sieve[i]:
            sieve[i * i :: 2 * i] = [False] * ((n - i * i - 1) // (2 * i) + 1)
    return [2] + [i for i in range(3, n, 2) if sieve[i]]


def solve():
    n = int(input())
    nums = list(map(int, input().split()))

    all_even = (nums[0] % 2 + nums[1] % 2 + nums[2] % 2) <= 1

    for i, num in enumerate(nums):
        target = 1 if all_even else 0
        if num % 2 == target:
            return i + 1


def main():
    print(solve())


if __name__ == "__main__":
    main()
