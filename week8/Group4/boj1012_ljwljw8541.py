#boj1012_ljwljw8541
from sys import stdin
input = stdin.readline
from collections import deque
T = int(input())
kx = [0,0,-1,1]
ky = [-1,1,0,0]
def bfs(x,y):
    q = deque([[x,y]])
    
    while q:
        nx,ny = q.popleft()
        
        for i in range(4):
            
            dx = nx + kx[i]
            dy = ny + ky[i]
            if 0<= dx <N and 0<= dy <M:
                if field[dx][dy] == 1:
                    q.append([dx,dy])
                    field[dx][dy] = 0
    
for _ in range(T):
    count = 0
    N,M,K = map(int, input().split())
    field = [[0]*(M) for _ in range(N)]
    for _ in range(K):
        x,y = map(int,input().split())
        field[x][y] = 1
    
    for i in range(N):
        for j in range(M):

            if field[i][j] == 1:
                
                bfs(i,j)
                
                count += 1
                
    print(count)