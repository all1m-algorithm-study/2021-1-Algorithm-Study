import sys
sys.setrecursionlimit(3000)
dx=[-1,-1,0,1,1,1,0,-1]
dy=[0,1,1,1,0,-1,-1,-1]
def landtosea(x,y,h,w):
    for i in range(8):
        if (0<=x+dx[i]<=h) and (0<=y+dy[i]<=w) and L[x+dx[i]][y+dy[i]]==1:
            L[x+dx[i]][y+dy[i]]=0
            landtosea(x+dx[i],y+dy[i],h,w)
    return
def DFS(c):
    for i in range(h):
        for j in range(w):
            if L[i][j]==1:
                L[i][j]=0
                landtosea(i,j,h-1,w-1)
                return DFS(c+1)
    else:
        return c
while 1:
    w, h = map(int, input().split())
    if (w,h)==(0,0):
        break
    L = []
    for _ in range(h):
        L.append(list(map(int, input().split())))
    print(DFS(0))