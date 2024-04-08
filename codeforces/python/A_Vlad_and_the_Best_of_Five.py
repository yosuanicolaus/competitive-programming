def solve():
    pass


def main():
    t = int(input())
    for _ in range(t):
        s = input()
        a, b = 0, 0
        for ch in s:
            if ch == "A":
                a += 1
            else:
                b += 1

        if a > b:
            print("A")
        else:
            print("B")


if __name__ == "__main__":
    main()
