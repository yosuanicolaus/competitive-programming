def solve(need_amount, multi_amount, single_price, multi_price):
    multi_price_per_one = multi_price / multi_amount
    need_to_buy = need_amount
    total_spent = 0

    if multi_price_per_one < single_price:
        # buying multi is cheaper
        while need_to_buy >= multi_amount:
            total_spent += multi_price
            need_to_buy -= multi_amount
        # for the final multi, check if buying remaining single is cheaper
        if need_to_buy > 0:
            total_spent += min(multi_price, need_to_buy * single_price)
    else:
        # buying single is cheaper
        total_spent = need_to_buy * single_price

    return total_spent


def main():
    n, m, a, b = map(int, input().split())
    print(solve(n, m, a, b))


if __name__ == "__main__":
    main()
