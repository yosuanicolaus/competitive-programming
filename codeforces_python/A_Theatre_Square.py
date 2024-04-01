from math import ceil


def solve():
    pass


def main():
    n, m, a = map(int, input().split())
    need_n = ceil(n / a)
    need_m = ceil(m / a)
    print(need_n * need_m)


if __name__ == "__main__":
    main()
