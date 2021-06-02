#boj2468_ljlwljw8541
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N = int(input())
matrix = [list(map(int, input().split())) for _ in range(N)]

kx = [0,0,-1,1]
ky = [-1,1,0,0]

def explore(x,y,matrix):
    if matrix[x][y] <= 0:
        return
    matrix[x][y] = -1
    for i in range(4):
        dx = x + kx[i]
        dy = y + ky[i]
        if 0 <= dx < N and 0 <= dy < N:
            explore(dx,dy,matrix)

Max = max(map(max, matrix))
def sol():
    count = 0
    global matrix
    for i in range(Max+1):
        #i칸씩 침수시킴.
        #k라는 새로운 list에 침수된 행렬 저장
        k = []
        for j in range(N):
            
            k.append(list(map(lambda x:x-i,matrix[j])))
        for r in range(N):
            for s in range(N):
                if k[r][s] < 0:
                    k[r][s] = 0
        #a는 count의 최댓값을 찾기 위한 변수
        a = 0
        for p in range(N):
            for q in range(N):
                if k[p][q] !=0 and k[p][q] != -1:
                    explore(p,q,k)
                    a += 1
        if a > count:
            count = a
    return count

print(sol())     