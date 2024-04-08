def solve():
    s = input()
    hh = int(s[:2])
    mm = int(s[3:])
    is_am = hh < 12

    if hh == 0:
        hh = 12
    elif hh > 12:
        hh -= 12

    return f"{str(hh).zfill(2)}:{str(mm).zfill(2)} {'AM' if is_am else 'PM'}"


def main():
    t = int(input())
    for _ in range(t):
        print(solve())


if __name__ == "__main__":
    main()
