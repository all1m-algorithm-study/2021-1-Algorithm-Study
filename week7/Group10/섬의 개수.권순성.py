import sys
sys.setrecursionlimit(10000)

w,h = map(int, input(), split())
dx = [-1, 0, 1, 0, 1, -1, -1, 1]
dy = [0, -1, 0, 1, 1, -1, 1, -1]

def dfs(vx, vy):
    maps[vx][vy]= 0 

    for i in range(8):
        nx = vx + dx[i]
        ny = vy + dy[i]
        if 0 <= nx < h and 0 <= ny< w and maps [nx][ny]== 1:
            dfs(nx,ny)


while h !=0 or w !=0:
    maps = [list(map(int, input().split())) for _ in range(h)]
    cnt = 0

    for x in range(h):
        if maps [x][y] == 1:
            cnt += 1
            dfs(x,y) 
    print(cnt)
    w,h= map(int,input().split())