#boj1012

def check_range(x, y):
    return 0 <= x < x_lim and 0 <= y < y_lim

def dfs(start_x, start_y):
    if farm[start_y][start_x] == 0:
        return
    farm[start_y][start_x] = 0

    for dx, dy in direction:
        nx = start_x + dx
        ny = start_y + dy
        if check_range(nx, ny) and farm[ny][nx] == 1:
            dfs(nx, ny)

direction = [(0,1), (0,-1), (1,0), (-1,0)]

test_case = int(input())
for _ in range(test_case):
    x_lim, y_lim, cabb_num = map(int, input().split())
    farm = [ [0 for _ in range(x_lim)] for _ in range(y_lim)]

    for _ in range(cabb_num):
        x, y = map(int, input().split())
        farm[y][x] = 1
        
    cnt = 0
    for row in range(x_lim):
        for col in range(y_lim):
            if farm[col][row] == 1:
                cnt += 1
                dfs(row, col)

    print(cnt)            
