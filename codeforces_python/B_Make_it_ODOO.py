def get_count(s: list[str]):
    return 4 - (
        int(s[0] == "O") + int(s[1] == "D") + int(s[2] == "O") + int(s[3] == "O")
    )


def solve(s: list[str]):
    best_count = 4

    for i in range(len(s) - 3):
        count = get_count(s[i : i + 4])
        best_count = min(best_count, count)

    return best_count + len(s) - 4


def main():
    t = int(input())
    for _ in range(t):
        s = list(input())
        print(solve(s))


if __name__ == "__main__":
    main()
