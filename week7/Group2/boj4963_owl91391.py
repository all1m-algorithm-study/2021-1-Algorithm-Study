import sys
input = sys.stdin.readline
from collections import deque

import sys
input = sys.stdin.readline
from collections import deque

dx = [-1,1,0,0,-1,-1,1,1]
dy = [0,0,-1,1,-1,1,-1,1]

def bfs(x, y, cnt):
    q = deque()
    q.append((x,y))
    visited[x][y] = 1
    while q:
        x,y = q.popleft()
        for k in range(8):
            nx = x+dx[k]
            ny = y+dy[k]
            if 0 <= nx < h and 0 <= ny < w:
                if data[nx][ny] == 1 and visited[nx][ny] == 0:
                    q.append((nx,ny))
                    visited[nx][ny] = 1
    
while True:
    w,h = map(int, input().split())
    if w == 0 and h == 0: break
    
    data = [ list(map(int, input().split())) for _ in range(h)]
    visited = [ [0] * (w) for _ in range(h)]
    cnt = 0
    for i in range(h):
        for j in range(w):
            if data[i][j] == 1 and visited[i][j] == 0:
                cnt += 1
                bfs(i, j, cnt)
    print(cnt)