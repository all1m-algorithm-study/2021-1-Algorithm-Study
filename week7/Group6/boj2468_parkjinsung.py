import sys
sys.setrecursionlimit(100000)

n = int(input())
graph = []

for i in range(n):
    graph.append(list(map(int, input().split())))

direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def DFS(start_x, start_y, h):
    for dx, dy in direction:
        nx = start_x + dx
        ny = start_y + dy
        if (0 <= nx < n) and (0 <= ny < n) and (visited[ny][nx] == False) and (graph[ny][nx] > h):
            visited[ny][nx] = True
            DFS(nx, ny, h)
            
cnt = -1
for h in range(max(map(max, graph))):
    visited = [[False for j in range(n)] for i in range(n)]
    temp_cnt = 0
    for y in range(n):
        for x in range(n):
            if (visited[y][x] == False) and graph[y][x] > h:
                temp_cnt += 1
                visited[y][x] = True
                DFS(x, y, h)

    if temp_cnt > cnt:
        cnt = temp_cnt
        
print(cnt)
