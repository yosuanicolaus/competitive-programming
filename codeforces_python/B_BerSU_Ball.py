def solve():
    pass


def main():
    lenboy = int(input())
    boys = list(map(int, input().split()))
    lengirl = int(input())
    girls = list(map(int, input().split()))

    pair_count = 0
    ib, ig = 0, 0
    boys.sort()
    girls.sort()

    while ib < lenboy and ig < lengirl:
        if abs(boys[ib] - girls[ig]) <= 1:
            pair_count += 1
            ib += 1
            ig += 1
        elif boys[ib] < girls[ig]:
            ib += 1
        else:
            ig += 1

    print(pair_count)


if __name__ == "__main__":
    main()
