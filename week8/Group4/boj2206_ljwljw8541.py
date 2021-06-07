#boj2206_ljwljw8541
from sys import stdin
from collections import deque
input = stdin.readline

N,M = map(int,input().split())
maze = [list(map(str,input().rstrip())) for _ in range(N)]
#벽을 부술수 있는 찬스는 단 한번!

kx = [0,0,1,-1]
ky = [1,-1,0,0]
visited = [[0]*M for _ in range(N)]

def bfs():
    distance = 0
    q = deque([])
    q.append([0,0,1])
    visited[0][0] = 1
    while q:
        
        for _ in range(len(q)):
            
            x,y,chance= q.popleft()
            
            if x == N-1 and y == M-1:
                return distance + 1
            
            for i in range(4):
                dx = x + kx[i]
                dy = y + ky[i]
                if 0<=dx<N and 0<=dy<M:
                    if visited[dx][dy] == 0 or visited[dx][dy] ==  2:
                        
                        if chance == 1:
                            visited[dx][dy] = 1

                            if maze[dx][dy] == '1':
                                q.append([dx,dy,0])
                                
                            elif maze[dx][dy] == '0':
                                q.append([dx,dy,1])
                                
                        elif chance == 0 and visited[dx][dy] == 0:
                            
                            if maze[dx][dy] == '0':
                                q.append([dx,dy,0])
                                visited[dx][dy] = 2
        distance += 1
        
    if visited[N-1][M-1] == 0:
        return -1

print(bfs())