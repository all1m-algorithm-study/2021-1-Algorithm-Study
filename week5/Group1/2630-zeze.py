num = int(input())
paper_list = []
for _ in range(num):
    paper_list.append(list(map(int, input().split())))

blue, white = 0, 0


def divide_square(x, y, num):
    global blue, white
    color = paper_list[x][y]
    check = True

    for i in range(x, x + num):
        if not check:
            break

        for j in range(y, y + num):
            if color != paper_list[i][j]:
                check = False
                divide_square(x, y, num//2)
                divide_square(x, y+num//2, num//2)
                divide_square(x+num//2, y, num//2)
                divide_square(x+num//2, y+num//2, num//2)
                break

    if check:
        if color:
            blue += 1
        else:
            white += 1


divide_square(0, 0, num)

print(white)
print(blue)