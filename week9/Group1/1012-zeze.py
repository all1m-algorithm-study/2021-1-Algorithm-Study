import sys 
from sys import setrecursionlimit
from collections import deque

setrecursionlimit(3000)

input = sys.stdin.readline

# 상하좌우
dx = [0, 0 ,-1, 1]
dy = [1, -1, 0, 0]

def bfs(x, y):
    for i in range(4):
        move_x = x + dx[i]
        move_y = y + dy[i]

        if (0 <= move_x < garo) and (0 <= move_y < sero):
            if bachu_map[move_x][move_y] == 1:
                # 배추가 있다면 해당 구역은 더이상 가지 않게 0으로 바꿈
                bachu_map[move_x][move_y] = 0
                bfs(move_x, move_y)
        



test_case = int(input())
for _ in range(test_case):
    count = 0
    garo, sero, bachu = map(int, input().split())
    # bachu_map = deque()
    # bachu_map = []
    bachu_map = [[0] * sero for _ in range(garo)]
    for _ in range(bachu):
        x, y = map(int, input().split())
        bachu_map[x][y] = 1
    # print(bachu_map)

    for i in range(garo):
        for j in range(sero):
            if bachu_map[i][j] == 1:
                count = count + 1
                bfs(i, j) 
                
    print(count)
