# solved with help from editorial
# lesson: don't be afraid to brute force if the upper limit is low


binary_decimals = []
for i in range(10, 10**5):
    for digit in str(i):
        if digit not in "01":
            break
    else:
        binary_decimals.append(i)


def solve():
    n = int(input())
    if n == 1:
        return "YES"

    while n not in binary_decimals:
        for bdec in binary_decimals:
            if n % bdec == 0:
                n = n // bdec
                break
        else:
            return "NO"

    return "YES"


def main():
    t = int(input())
    for _ in range(t):
        print(solve())


if __name__ == "__main__":
    main()
