#boj7576_ljwljw8541
import sys
input = sys.stdin.readline
from collections import deque

M,N = map(int,input().split())

store = [list(map(int, input().split())) for _ in range(N)]

kx = [0,0,-1,1]
ky = [-1,1,0,0]
def bfs():
    q =deque([])
    #1인 인덱스를 탐색 후 append
    for i in range(N):
        for j in range(M):
            if store[i][j] == 1:
                q.append([i,j,0])
    
    while q:
        now_x,now_y,day = q.popleft()
        #전형적인 상하좌우
        for i in range(4):
            next_x = now_x + kx[i]
            next_y = now_y + ky[i]
            if 0 <= next_x < N and 0 <= next_y < M:
                    #next가 안익어었다면 1로 바꿈.
                if store[next_x][next_y] == 0:
                    store[next_x][next_y] = 1
                    q.append([next_x,next_y,day+1])
        
    #while 문이 끝난후에도 0이 있으면 -1을 출력
    for i in range(N):
        for j in range(M):
            if store[i][j] == 0:
                return -1
    return day

print(bfs())