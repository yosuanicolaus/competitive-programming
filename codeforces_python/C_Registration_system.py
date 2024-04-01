def solve():
    pass


def main():
    t = int(input())
    db = {}

    for _ in range(t):
        name = input()

        if name in db:
            print(f"{name}{db[name]}")
            db[name] += 1
        else:
            print("OK")
            db[name] = 1


if __name__ == "__main__":
    main()
