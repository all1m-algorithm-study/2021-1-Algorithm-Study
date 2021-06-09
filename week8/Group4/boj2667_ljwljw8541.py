#boj2667_ljwljw8541
import sys
input = sys.stdin.readline
from collections import deque

N = int(input())
Map = [list(map(str,input())) for _ in range(N)]

kx = [0,0,-1,1]
ky = [-1,1,0,0]
visited =[[0]*(N) for _ in range(N)]

def bfs(x,y):
    q = deque([])
    q.append([x,y])
    cnt = 0
    while q:
        
        now_x,now_y = q.popleft()
        cnt += 1 
        Map[now_x][now_y] = '0'
        visited[now_x][now_y] = 1
        for i in range(4):
            next_x = now_x + kx[i]
            next_y = now_y + ky[i]
            if 0<=next_x<N and 0<=next_y<N:
                if Map[next_x][next_y] == '1' and visited[next_x][next_y] == 0\
                    and not [next_x,next_y] in q:
                    q.append([next_x,next_y])
                    
                    
    return cnt
complex_cnt = 0

k = []
for i in range(N):
    for j in range(N):
        if Map[i][j] == '1':

            k.append(bfs(i,j))
            complex_cnt += 1
print(complex_cnt)
k.sort()
for c in k:
    print(c)
