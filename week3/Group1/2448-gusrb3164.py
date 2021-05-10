def main():
    num = int(input())
    global Map
    Map = [[' ']*(num*2-1) for _ in range(num)]
    drawStar(num-1, 0, num)
    for line in Map:
        print("".join(line))


def drawStar(col, row, height):
    if height == 3:
        Map[row][col] = '*'
        Map[row+1][col-1] = Map[row+1][col+1] = '*'
        for i in range(5):
            Map[row+2][col-2 + i] = '*'

    else:
        nextHeight = height//2
        drawStar(col, row, nextHeight)
        drawStar(col-nextHeight, row+nextHeight, nextHeight)
        drawStar(col+nextHeight, row+nextHeight, nextHeight)


if __name__ == "__main__":
    main()
