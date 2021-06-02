import sys
sys.setrecursionlimit(1000000)

M, N = map(int, input().split(' '))

grid = [list(map(int, list(input()))) for m in range(M)]
direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def dfs(row, col):
    grid[row][col] = -1
    for x, y in direction:
        new_row = row + y
        new_col = col + x
        if 0 <= new_row < M and 0 <= new_col < N and grid[new_row][new_col] == 0:
            dfs(new_row, new_col)

for i in range(N):
    if grid[0][i] == 0:
        dfs(0, i)

result = False
for i in range(N):
    if grid[M-1][i] == -1:
        result = True
        break

if result:
    print('YES')
else:
    print('NO')