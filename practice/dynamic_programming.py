# Practice DP
# https://youtu.be/Clp5c7HvLqs?si=OzfbzxFQeiDAYluh

# dp_frog: a frog can only jump 1 or 2 tiles to the right
# how many available paths are there
# (also called fibonacci in disguise)

# dp_ksp: given an array of int and target sum,
# is it possible to sum some elements from the array to get exactly the target sum?
# ans: you can either take or not take each element from the array

# dp_grid: ... -_-
# TRICK QUESTION! It's not solvable with dp -_-
# ans: backtracking


def dp_frog(n: int, current: int, memo={}):
    if current in memo:
        return memo[current]
    if current > n:
        return 0
    if current == n:
        return 1

    memo[current] = dp_frog(n, current + 1) + dp_frog(n, current + 2)
    return memo[current]


def dp_ksp(arr, target_sum, carry_sum, idx, memo={}):
    if idx == len(arr):
        return False
    if (carry_sum, idx) in memo:
        return memo[(carry_sum, idx)]
    if carry_sum > target_sum:
        return False
    if carry_sum == target_sum:
        return True

    # to take
    val_take = dp_ksp(arr, target_sum, carry_sum + arr[idx], idx + 1, memo)
    # or not to take
    val_not_take = dp_ksp(arr, target_sum, carry_sum, idx + 1, memo)

    res = any((val_take, val_not_take))
    memo[(carry_sum, idx)] = res
    return res


def dp_grid(grid: list[list[int]], visited: set, pos_y, pos_x, memo: dict):
    if pos_y < 0 or pos_y >= len(grid) or pos_x < 0 or pos_x >= len(grid[0]):
        return 0
    if (pos_y, pos_x) in visited:
        return 0
    # if (visited, pos_y, pos_x) in memo:
    #     return memo[(visited, pos_y, pos_x)]
    if len(visited) == len(grid) * len(grid[0]):
        return 1

    visited.add((pos_y, pos_x))

    # go to all 4 directions
    go_up = dp_grid(grid, visited, pos_y - 1, pos_x, memo)
    go_down = dp_grid(grid, visited, pos_y + 1, pos_x, memo)
    go_left = dp_grid(grid, visited, pos_y, pos_x - 1, memo)
    go_right = dp_grid(grid, visited, pos_y, pos_x + 1, memo)

    res = sum((go_up, go_down, go_left, go_right))
    # memo[(visited, pos_y, pos_x)] = res
    return res


def solve():
    # n = int(input())
    # return dp_frog(n, current=0, memo={})

    # arr = list(map(int, input().split()))
    # target_sum = int(input())
    # return dp_ksp(arr, target_sum, 0, 0, {})

    n = int(input())
    grid = [[0] * n for _ in range(n)]
    return dp_grid(grid, set(), 0, 0, {})


def main():
    print(solve())


if __name__ == "__main__":
    main()
