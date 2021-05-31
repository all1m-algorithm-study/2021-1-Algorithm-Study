# N x N


import sys
input = sys.stdin.readline

def is_same(field, y, x, leng):
    selected = None
    for i in range(y, y+leng):
        for j in range(x, x+leng):
            if selected == None:
                selected = field[i][j]
            elif field[i][j] != selected:
                return -1 # different
    return selected # return 0 if white else 1 (blue)

def cut(field, y, x, leng):
    global white, blue
    flag = is_same(field, y, x, leng)
    if flag == -1:
        half = leng//2
        cut(field, y, x, half)
        cut(field, y + half, x, half)
        cut(field, y, x + half, half)
        cut(field, y + half, x + half, half)
    else:
        if flag == 0:
            white += 1
        else:
            blue += 1

def solution(N):
    field = [list(map(int, input().split())) for _ in range(N)]
    cut(field, 0, 0, N)

if __name__ == '__main__':
    white = blue = 0
    solution(int(input()))
    print(white)
    print(blue)