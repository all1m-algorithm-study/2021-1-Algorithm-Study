import sys

input = sys.stdin.readline

sys.setrecursionlimit(10 ** 6)

global input_map

def dfs(i, j):
        if i < 0 or j < 0 or i >= len(input_map) or j >= len(input_map[0]) or input_map[i][j] != 1:
            return

        input_map[i][j] = 0

        # 동서남북대각선 비교
        dfs(i, j + 1)
        dfs(i, j - 1)
        dfs(i + 1, j)
        dfs(i - 1, j)
        dfs(i - 1, j - 1)
        dfs(i - 1, j + 1)
        dfs(i + 1, j - 1)
        dfs(i + 1, j + 1)

        # input_map[i][j] = 0 여기다 하면 재귀 다 돌아서 재귀 깊이 초과돼서 에러남

while(1):
    w, h = map(int, input().split()) # 열행 입력받기
    if w == 0 and h == 0:
        break
    input_map = [list(map(int, input().split())) for _ in range(h)]

    count = 0

    for i in range(h):
        for j in range(w):
            if input_map[i][j] == 1:
                dfs(i, j)
                count += 1
    
    print(count)