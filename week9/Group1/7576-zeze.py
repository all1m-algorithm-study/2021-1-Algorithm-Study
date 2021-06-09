import sys
from collections import deque

input = sys.stdin.readline

garo, sero = map(int, input().split())

# 상하좌우
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def bfs():
    count = 0
    while ripe_tomato:
        count += 1
        # que 길이만큼 탐색해야 익은 토마토 상하좌우만 탐색 후 count 1만 증가시킴
        for _ in range(len(ripe_tomato)):
            y, x = ripe_tomato.popleft()
            for i in range(4):
                move_x = x + dx[i]
                move_y = y + dy[i]
                
                if (0 <= move_x < garo) and (0 <= move_y < sero):
                        if tomato[move_y][move_x] == 0:
                            tomato[move_y][move_x] = 1
                            ripe_tomato.append([move_y, move_x])
    return count


# 토마토 밭 전체 입력
tomato = [list(map(int, input().split())) for _ in range(sero)]
# 익은 토마토 위치만 저장할 que 선언
ripe_tomato = deque()
# 익은 토마토 위치를 que에 저장
for y in range(sero):
    for x in range(garo):
        if tomato[y][x] == 1:
            ripe_tomato.append([y, x])

# 1을 빼는 이유는 처음 익은 토마토를 발견하면서부터 count가 1이 되어서 처음 발견할 때 증가한 1을 빼줘야 함
answer =  bfs() - 1 

# 하나라도 못 익은게 있으면 종료
for y in range(sero):
    for x in range(garo):
        if tomato[y][x] == 0:
            print(-1)
            exit()

print(answer)



