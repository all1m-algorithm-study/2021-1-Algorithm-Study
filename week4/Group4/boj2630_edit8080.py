# 1. 전체가 동일한지 확인한다.
# 2. 전체가 동일하면 해당 색깔을 카운팅한다.
# 3. 동일하지 않다면 4등분으로 분할하고 1~2 과정을 반복한다.
# 4. 분할된 크기가 1개면 분할을 종료하고 해당 색깔을 카운팅한다.
#
# 시간복잡도 = O(n^2 lgn) 전체 탐색 x 최대 lgn 번

n = int(input())
paper = [list(map(int, input().split(" "))) for _ in range(n)]
color = [0 for _ in range(2)]


def is_equal(x, y, size):
    standard = paper[x][y]

    for i in range(size):
        for j in range(size):
            if paper[x + i][y + j] != standard:
                return False
    return True


def divide(x, y, size):
    if size == 1:
        color[paper[x][y]] += 1
        return

    if is_equal(x, y, size):
        color[paper[x][y]] += 1

    else:
        for i in range(0, size, size // 2):
            for j in range(0, size, size // 2):
                divide(x + i, y + j, size // 2)
    return


divide(0, 0, n)
print("%d\n%d" % (color[0], color[1]))
