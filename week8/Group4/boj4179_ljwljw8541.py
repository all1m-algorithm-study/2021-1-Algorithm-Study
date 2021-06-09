#boj4179_ljwljw8541
from sys import stdin
input = stdin.readline
from collections import deque
R,C = map(int, input().split())
maze = [list(map(str, input())) for _ in range(R)]
kx = [0,0,-1,1]
ky = [-1,1,0,0]
#J를 위한 방문확인
visited = [[False]*C for _ in range(R)]
q = deque([])
#J의 인덱스 확인
for i in range(R):
    for j in range(C):
        if maze[i][j] == 'J':
            q.append([i,j])
            break
#for 문 2개 쓴이유는 J->F 순서로 append하려고
#F의 인덱스 확인
for i in range(R):
    for j in range(C):
        if maze[i][j] == 'F':
            q.append([i,j])
minute = 0
def bfs():
    global minute
    while q:
        #맨처음 시작할때 q의 개수가 여러개라서 len(q)만큼 돌려야함.
        for _ in range(len(q)):
            now_x,now_y = q.popleft()
            #현재 인덱스가 J라면
            if maze[now_x][now_y] == 'J':
                #근데 그 인덱스가 가장자리 부분이면 탈출에 성공한 것이므로 return
                #+1은 탈출하는데 드는 시간?
                if now_x == 0 or now_x == R-1 or now_y == 0 or now_y == C-1:
                    return minute + 1
                #전형적인 앞뒤양옆 탐색
                for i in range(4):
                    next_x = now_x + kx[i]
                    next_y = now_y + ky[i]
                    if 0 <= next_x < R and 0 <= next_y < C :
                        #다음 인덱스가 . 이면서 방문하지 않았다면
                        if maze[next_x][next_y] == '.' and not visited[next_x][next_y]:

                            
                            maze[next_x][next_y] = 'J'
                            maze[now_x][now_y] = '.'
                            visited[next_x][next_y] = True
                            q.append([next_x,next_y])
            #현재 인덱스가 F라면
            elif maze[now_x][now_y] == 'F':
                #전형적인 앞뒤양옆 탐색
                for i in range(4):
                    next_x = now_x + kx[i]
                    next_y = now_y + ky[i]
                    if 0 <= next_x < R and 0 <= next_y < C :
                        #.에도 번질수 있고 J에도 번질수 있음.
                        # J가 이동한 후에 F가 J에 번진다면 탈출하지 못하는것
                        #J가 사라지므로 while 문이 끝난후에 return IMPOSSIBLE 이 됨.
                        if maze[next_x][next_y] == '.' or maze[next_x][next_y] == 'J':
                            maze[next_x][next_y]= 'F'
                            q.append([next_x,next_y])
        minute += 1
    #while 문이 끝날때 까지 return이 안되었다면 탈출하지 못한것
    if minute != 0:
        #예외 처리: J가 처음부터 가장자리에 있었다면 
        # IMPOSSIBLE 이 아니라 1을 출력해야함.
        return 'IMPOSSIBLE'

print(bfs())