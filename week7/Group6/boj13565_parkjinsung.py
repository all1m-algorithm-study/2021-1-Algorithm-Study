import sys
sys.setrecursionlimit(3000000)

def DFS(y, x):
    graph[y][x] = 2
    for dy, dx in d:
        Y, X = y+dy, x+dx
        if (0 <= Y < M) and (0 <= X < N) and graph[Y][X] == 0:
            DFS(Y, X)
            
M, N = map(int, input().split())
graph = [list(map(int, list(input()))) for _ in range(M)]
d = [(-1, 0), (1, 0), (0, -1), (0, 1)]
for j in range(N):
    if graph[0][j] == 0:
        DFS(0, j)

if 2 in graph[-1]:
    print("YES")
else:
    print("NO")
