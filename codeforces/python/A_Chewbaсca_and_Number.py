def solve():
    pass


def main():
    digits = list(input())
    for i, digit in enumerate(digits):
        if digit in "56789":
            inverted = str(9 - int(digit))
            digits[i] = inverted

    if len(digits) > 0 and digits[0] == "0":
        digits[0] = "9"

    print("".join(digits))


if __name__ == "__main__":
    main()
