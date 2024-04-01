def solve():
    pass


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        dist = n - 1
        ans = n * (k // dist)
        if k % dist == 0:
            ans -= 1
        else:
            ans += k % dist
        print(ans)


if __name__ == "__main__":
    main()
