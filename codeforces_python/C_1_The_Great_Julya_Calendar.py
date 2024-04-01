# https://codeforces.com/problemset/problem/331/C1
# brute force works for the first case, n < 10**6, and codeforces accepts it
# but 2nd case and 3rd case requires more thought
# try it in the future


def solve():
    n = int(input())
    operation = 0

    while n > 0:
        for digit in "987654321":
            if digit in str(n):
                n -= int(digit)
                operation += 1
                break

    return operation


def main():
    print(solve())


if __name__ == "__main__":
    main()
