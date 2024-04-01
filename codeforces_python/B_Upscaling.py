def solve(n: int) -> list[str]:
    ans = [["." for _ in range(n * 2)] for _ in range(n * 2)]

    for y in range(0, n * 2, 2):
        for x in range(0, n * 2, 2):
            if y % 4 == 0:
                if x % 4 == 0:
                    ans[y][x] = "#"
                    ans[y][x + 1] = "#"
                    ans[y + 1][x] = "#"
                    ans[y + 1][x + 1] = "#"
            elif y % 2 == 0:
                if (x + 2) % 4 == 0:
                    ans[y][x] = "#"
                    ans[y][x + 1] = "#"
                    ans[y + 1][x] = "#"
                    ans[y + 1][x + 1] = "#"

    return ans


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        ans = solve(n)
        for ch_list in ans:
            print("".join(ch_list))


if __name__ == "__main__":
    main()
