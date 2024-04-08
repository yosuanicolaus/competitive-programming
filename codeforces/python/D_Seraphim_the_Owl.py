# TLE on tc7


def solve():
    n, m = map(int, input().split())
    replace_costs = list(map(int, input().split()))
    overtake_costs = list(map(int, input().split()))
    final_cost = replace_costs[m - 1]

    def get_min_cost(from_range, to_range):
        min_cost = 0
        for i in range(from_range, to_range):
            min_cost += min(replace_costs[i], overtake_costs[i])
        return min_cost

    # get cheapest final_cost
    for i in range(m - 1):
        temp_cost = replace_costs[i] + get_min_cost(i + 1, m)
        final_cost = min(final_cost, temp_cost)

    # get journey (just to before the max allowed) cost
    journey_cost = get_min_cost(m, n)
    return final_cost + journey_cost


def main():
    t = int(input())
    for _ in range(t):
        print(solve())


if __name__ == "__main__":
    main()
