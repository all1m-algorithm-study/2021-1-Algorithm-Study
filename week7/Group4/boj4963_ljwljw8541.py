#boj4963_ljwljw8541
from sys import stdin
input = stdin.readline
from sys import setrecursionlimit
setrecursionlimit(10**6)

kx = [0,0,-1,1,-1,-1,1,1]
ky = [-1,1,0,0,-1,1,-1,1]

visited = []
def island(x,y):
    
    if visited[x][y] == 1 or matrix[x][y] == 0:
        return

    visited[x][y] = 1
    
    for i in range(8):
        dx = x + kx[i]
        dy = y + ky[i]
        if 0 <= dx < h and 0<= dy < w:
            island(dx,dy)

w,h = map(int,input().split())
while w != 0 or h != 0:
    
    matrix = [list(map(int,input().split())) for _ in range(h)]

    count = 0
    visited = [[0]*w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            if visited[i][j] != 1 and matrix[i][j] == 1:
                island(i,j)
                count += 1
    print(count)
    w,h = map(int,input().split())
