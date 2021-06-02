import sys
input = sys.stdin.readline
from collections import deque

def bfs(x,y) :
    que=deque([])
    que.append((x,y))
    visited[x][y] =1
    while que :
        x,y = que.popleft()
        for k in range(4) :
            nx= x+dx[k]
            ny= y+dy[k]
            if 0<=nx<n and 0<=ny<n :
                if arr[nx][ny] !=0 and visited[nx][ny] == 0 :
                    que.append((nx,ny))
                    visited[nx][ny] = 1

n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]

dx = [-1,1,0,0]
dy = [0,0,-1,1]

hi_num = max(map(max,arr))
cnt_list =[]

for i in range(0,101) :
    cnt=0
    visited = [[0]*n for _ in range(n)]
    for x in range(n) :
        for y in range(n) :
            if arr[x][y] <= i :
                arr[x][y] =0
    for x in range(n) :
        for y in range(n) :
            if arr[x][y] != 0 and visited[x][y]==0 :
                cnt +=1
                bfs(x,y)
    cnt_list.append(cnt)
print(max(cnt_list))