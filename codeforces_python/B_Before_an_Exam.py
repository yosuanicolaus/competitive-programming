def solve(sumtime: int, min_times: list[int], max_times: list[int]):
    ans = []
    remaining = sumtime

    for min_time in min_times:
        ans.append(min_time)
        remaining -= min_time

    i = 0
    while remaining > 0:
        capacity = max_times[i] - min_times[i]
        if remaining > capacity:
            ans[i] = max_times[i]
            remaining -= capacity
        else:
            ans[i] = min_times[i] + remaining
            break
        i += 1

    return " ".join(map(str, ans))


def main():
    d, sumtime = map(int, input().split())
    min_times = []
    max_times = []
    sum_min = 0
    sum_max = 0

    for _ in range(d):
        min_t, max_t = map(int, input().split())
        sum_min += min_t
        sum_max += max_t
        min_times.append(min_t)
        max_times.append(max_t)

    if sumtime < sum_min or sumtime > sum_max:
        print("NO")
    else:
        print("YES")
        print(solve(sumtime, min_times, max_times))


if __name__ == "__main__":
    main()
