def solve(tasks: list[int], time: int):
    if max(tasks) > time:
        return -1

    server_count = 0
    server_carry = 0

    for task in tasks:
        if server_carry >= task:
            server_carry -= task
        else:
            server_count += 1
            server_carry = time - task

    return server_count


def main():
    _, time = map(int, input().split())
    tasks = list(map(int, input().split()))
    print(solve(tasks, time))


if __name__ == "__main__":
    main()
