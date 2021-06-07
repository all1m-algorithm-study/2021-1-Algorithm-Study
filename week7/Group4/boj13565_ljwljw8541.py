#boj13565_ljwljw8541
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

M,N = map(int, input().split())
matrix = [list(map(int,input().rstrip())) for _ in range(M)]

kx = [0,0,-1,1]
ky = [-1,1,0,0]

def percolate(x,y):
    if matrix[x][y] != 0:
        return
    matrix[x][y] = 2

    for i in range(4):
        dx = x + kx[i]
        dy = y + ky[i]
        if 0 <= dx <M and 0 <= dy < N:
            percolate(dx,dy)

for c in range(N):
    if matrix[0][c] == 0:
        percolate(0,c)


if 2 in matrix[M-1]:
    print('YES')
else:
    print('NO')
