#boj2667
import sys
sys.setrecursionlimit(1000000)

n = int(input())
ground = []
for _ in range(n):
    ground.append(list(input()))

def check_range(x, y):
    return 0 <= x < len(ground[0]) and 0 <= y < len(ground)

def dfs(start_x, start_y):
    global house_cnt
    if ground[start_y][start_x] == '0':
        return
    house_cnt += 1
    ground[start_y][start_x] = '0'

    for dx, dy in direction:
        nx = start_x + dx
        ny = start_y + dy
        if check_range(nx, ny) and ground[ny][nx] == '1':
            dfs(nx, ny)
            
direction = [(0,1), (0,-1), (1,0), (-1,0)]
apart = 0
house = []
for row in range(len(ground[0])):
    for col in range(len(ground)):
        house_cnt = 0
        if ground[col][row] == '1':
            apart += 1
            dfs(row, col)
            house.append(house_cnt)
            
print(apart)
house.sort()
for i in house:
    print(i)
