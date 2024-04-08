def solve(arr1: list[str], arr2: list[str]):
    a, b = 1, 0

    while a < len(arr1) and b < len(arr2):
        if arr1[a] == "<" and arr2[b] == "<":
            return "NO"
        if a < b:
            a += 2
        else:
            b += 2

    return "YES"


def main():
    t = int(input())
    for _ in range(t):
        _ = int(input())
        arr1 = list(input())
        arr2 = list(input())
        print(solve(arr1, arr2))


if __name__ == "__main__":
    main()
