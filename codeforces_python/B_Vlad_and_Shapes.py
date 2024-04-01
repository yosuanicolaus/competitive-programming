def solve(grid: list[str]):
    prev_c1 = 0

    for row in grid:
        c1 = row.count("1")

        if prev_c1 != 0:
            if c1 != prev_c1:
                return "TRIANGLE"
            elif c1 == prev_c1:
                return "SQUARE"

        prev_c1 = c1


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        grid = []

        for _ in range(n):
            s = input()
            grid.append(s)

        print(solve(grid))


if __name__ == "__main__":
    main()
