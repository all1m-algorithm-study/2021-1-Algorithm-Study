import sys
from collections import deque

input = sys.stdin.readline

num = int(input())
# 단지 입력
apartment_map = [list(input()) for _ in range(num)]
# 아파트가 있는 위치를 que에 넣을거임
que = deque()
answer_list = []
total = 0

# 상하좌우
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]


def bfs():
    count = 1
    while que:
        x, y = que.popleft()
        for i in range(4):
            move_x = x + dx[i]
            move_y = y + dy[i]

            if (0 <= move_x < num) and (0 <= move_y < num):
                if apartment_map[move_x][move_y] == '1':
                    count += 1
                    # 탐색한 곳은 0으로
                    apartment_map[move_x][move_y] = '0'
                    que.append([move_x, move_y])
                    
    return answer_list.append(count)              


for i in range(num):
    for j in range(num):
        if apartment_map[i][j] == '1':
            # apartment_map[0][0] = 1 이면 bfs 함수에서 apartment_map[0][0]을 0으로 안 바꿔줘서
            # apartment_map[0][1]이 탐색할 때 apartment_map[0][0]도 한 번더 count로 추가함😢
            apartment_map[i][j] = 0
            que.append([i, j])
            total += 1
            bfs()

# 단지 수
print(total)

# 오름차순 출력
answer_list.sort()
for i in range(total):
    print(answer_list[i])
