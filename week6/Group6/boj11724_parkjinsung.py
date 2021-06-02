import sys
sys.setrecursionlimit(10000)

n , m = map(int, input().split())

graph = [[] for i in range(n+1)]
visited = [False for i in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def DFS(graph, start, visited):
    if visited[start]:
        return
    visited[start] = True
    
    for i in graph[start]:
        DFS(graph, i, visited)
    
temp = list(visited)
cnt = 0
for i in range(1, n+1):
    DFS(graph, i, visited)
    if temp != visited:
        cnt += 1
        temp = list(visited)
    
print(cnt)
