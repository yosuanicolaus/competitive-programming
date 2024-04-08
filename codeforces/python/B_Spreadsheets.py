# Stuck for ~2 hours on get_num_col_equivalent, then...
# asked chatGPT and it gave me that. damn.
# so much simpler than my complicated approach...
# lesson: wtf man. I don't know
# I guess you should time yourself, and know when to look for answer


import re


def get_col_num_equivalent(col: str):
    return ord(col) - ord("A") + 1


def get_num_col_equivalent(num: int):
    columns = []
    while num > 0:
        remainder = (num - 1) % 26
        columns.append(chr(ord("A") + remainder))
        num = (num - 1) // 26
    columns.reverse()
    return "".join(columns)


def is_rxcy_format(s):
    pattern = r"^R\d+C\d+$"
    return bool(re.match(pattern, s))


def rxcy_to_column(rxcy: str):
    for i, rxcy_ch in enumerate(rxcy):
        if rxcy_ch == "C":
            ans_row = int(rxcy[1:i])
            ans_col = get_num_col_equivalent(int(rxcy[i + 1 :]))
            return f"{''.join(ans_col)}{ans_row}"


def column_to_rxcy(column: str):
    for row_idx, ch in enumerate(column):
        if ch in "123456789":
            ans_row = int(column[row_idx:])
            ans_col = 0
            factor = 0

            for col_idx in range(row_idx - 1, -1, -1):
                ans_col += 26**factor * get_col_num_equivalent(column[col_idx])
                factor += 1

            return f"R{ans_row}C{ans_col}"


def main():
    t = int(input())
    for _ in range(t):
        coordinate = input()
        if is_rxcy_format(coordinate):
            print(rxcy_to_column(coordinate))
        else:
            print(column_to_rxcy(coordinate))


if __name__ == "__main__":
    main()
