import string


def solve(s: str):
    if len(s) < 11 or len(s) > 13:
        return "no"
    if s[-9:] != "@odoo.com":
        return "no"

    lib = string.ascii_lowercase

    for ch in s[:-9]:
        if ch not in lib:
            return "no"

    return "yes"


def main():
    s = input()
    print(solve(s))


if __name__ == "__main__":
    main()
