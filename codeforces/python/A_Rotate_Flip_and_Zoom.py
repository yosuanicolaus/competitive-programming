def solve():
    pass


def main():
    w, h = map(int, input().split())
    pic = []
    for _ in range(h):
        pic.append(list(input()))

    # rotate 90 degree clockwise
    new_pic = [["."] * h for _ in range(w)]
    pt_y_old, pt_x_old = 0, 0
    pt_y_new, pt_x_new = 0, h - 1

    while pt_y_new < w:
        new_pic[pt_y_new][pt_x_new] = pic[pt_y_old][pt_x_old]
        pt_y_new += 1
        pt_x_old += 1
        if pt_y_new == w and pt_x_new > 0:
            pt_y_new = 0
            pt_x_new -= 1
            pt_y_old += 1
            pt_x_old = 0

    # flip horizontally
    for pic_list in new_pic:
        pic_list.reverse()

    final_pic = [["."] * h * 2 for _ in range(w * 2)]
    for y in range(w):
        for x in range(h):
            if new_pic[y][x] == "*":
                final_pic[y * 2][x * 2] = "*"
                final_pic[y * 2][x * 2 + 1] = "*"
                final_pic[y * 2 + 1][x * 2] = "*"
                final_pic[y * 2 + 1][x * 2 + 1] = "*"

    for s in final_pic:
        print("".join(s))


if __name__ == "__main__":
    main()
