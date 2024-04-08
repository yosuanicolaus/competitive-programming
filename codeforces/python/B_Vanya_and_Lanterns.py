def solve():
    pass


def main():
    n, l = map(int, input().split())
    lanterns = list(map(int, input().split()))
    lanterns.sort()
    highest_dist = max(lanterns[0] * 2, (l - lanterns[-1]) * 2)

    for i in range(len(lanterns) - 1):
        new_dist = lanterns[i + 1] - lanterns[i]
        highest_dist = max(highest_dist, new_dist)

    print(highest_dist / 2)


if __name__ == "__main__":
    main()
