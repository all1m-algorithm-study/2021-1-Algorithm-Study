알파벳========

import sys
sys.setrecursionlimit(10000)

dx = [1,-1,0,0]
dy = [0,0,1,-1]

r, c = map(int,sys.stdin.readline().split())
arr = [list(map(lambda x: ord(x)-65, input())) for _ in range(r)]

ans = 1

vis = [False for _ in range(26)]
vis[arr[0][0]] = True

def dfs(x,y,cnt):
    global ans
    ans = max(ans,cnt)

    for i in range(4):
        newx = x + dx[i]
        newy = y + dy[i]

        if 0 <= newx < r and 0 <= newy < c:
            if vis[arr[newx][newy]] == False:
                vis[arr[newx][newy]]  = True
                
                dfs(newx,newy,cnt+1)
                vis[arr[newx][newy]] = False

dfs(0,0,ans)
print(ans)
