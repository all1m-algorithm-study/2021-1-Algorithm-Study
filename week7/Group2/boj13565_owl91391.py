def dfs(y,x) :
    stack=[]
    stack.append((y,x))
    visited[y][x] =1
    while stack :
        y,x = stack.pop()
        for k in range(4) :
            nx= x+dx[k]
            ny= y+dy[k]
            if 0<=nx<n and 0<=ny<m :
                if arr[ny][nx] ==0 and visited[ny][nx] == 0 :
                    stack.append((ny,nx))
                    visited[ny][nx] = 1

m, n = map(int,input().split())
arr = [list(map(int,input())) for _ in range(m)]

dx = [-1,1,0,0]
dy = [0,0,-1,1]
visited = [[0]*n for _ in range(m)]
for i in range(n) :
    if arr[0][i] == 0:
        dfs(0,i)

if max(visited[-1]) == 1:
    print("YES")
else :
    print("NO")