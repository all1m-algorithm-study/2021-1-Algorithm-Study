import sys
from collections import deque

input = sys.stdin.readline

sero, garo = map(int, input().split())
map_list = [list(input()) for _ in range(sero)]
# 3차원 배열
# [[[걸린 시간, 벽을 뚫었는지의 여부(0은 뚫은 거, 1은 아직 안 뚫은 상태)]]]
time = [[[0]*2 for _ in range(garo)] for _ in range(sero)]
# print(visited)
que = deque()

# 상하좌우
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def bfs():
    que.append([0, 0, 1])
    # 첫 번째 방문
    time[0][0][1] = 1
    while que:
        x, y, wall = que.popleft()
        if x == sero - 1 and y == garo -1:
            # print(time)
            return time[sero - 1][garo -1][wall]
        for i in range(4):
            move_x = x + dx[i]
            move_y = y + dy[i]

            if (0 <= move_x < sero) and (0 <= move_y < garo):
                # 벽을 뚫지 않은 상태에서 벽을 마주했고 벽을 뚫고 갈려고 할 때
                if wall == 1 and map_list[move_x][move_y] == '1':
                    time[move_x][move_y][0] = time[x][y][1] + 1
                    # 이제부터 벽을 뚫은 상태로 저장
                    que.append([move_x, move_y, 0])
                # 길이고 아직 방문 전일 때
                # 길이기 때문에 벽을 뚫었는지 안 뚫었는지 알 수 있는 변수 wall은 중요치 x
                elif map_list[move_x][move_y] == '0' and time[move_x][move_y][wall] == 0:
                    # 그 전의 경로에서 시간을 1 추가함
                    time[move_x][move_y][wall] = time[x][y][wall] + 1
                    que.append([move_x, move_y, wall])
    
    # 최단거리 출력이 불가할 때
    return -1

print(bfs())

