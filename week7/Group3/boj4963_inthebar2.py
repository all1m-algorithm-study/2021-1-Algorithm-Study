import sys
sys.setrecursionlimit(10**9)

directions = [(-1, -1), (0, -1), (-1, 0), (1, 1), (1, 0), (0, 1), (1, -1), (-1, 1)]
visited = []


def isValidIndex(w, h, current_row, current_col):
    return 0 <= current_row < h and 0 <= current_col < w


def dfs(island, w, h, current_row, current_col):
    global visited
    visited[current_row][current_col] = True

    for direction in directions:
        row, col = current_row + direction[0], current_col + direction[1]
        if isValidIndex(w, h, row, col) and visited[row][col] == False and island[row][col]:
            dfs(island, w, h, row, col)

while True:
    w, h = map(int, input().split(' '))

    if w == 0 or h == 0:
        break

    cnt = 0
    visited = [[False for i in range(w)] for i in range(h)]
    island = []

    for _ in range(h):
        island.append(list(map(int, input().split(' '))))
    
    for i in range(h):
        for j in range(w):
            if island[i][j] and visited[i][j] == False:
                cnt += 1
                dfs(island, w, h, i, j)

    print(cnt)