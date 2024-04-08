# TLE again
# wtf python
# I will try this with c++ later


def solve():
    len_arr = int(input())
    arr = map(int, input().split())

    highest_common = 0
    num_count = {}
    for num in arr:
        num_count.setdefault(num, 0)
        num_count[num] += 1
        highest_common = max(highest_common, num_count[num])

    opr_swap = len_arr - highest_common
    opr_copy = 0
    swapped = 0

    while swapped < opr_swap:
        opr_copy += 1
        swapped += highest_common
        highest_common *= 2

    return opr_swap + opr_copy


def main():
    t = int(input())
    for _ in range(t):
        print(solve())


if __name__ == "__main__":
    main()
