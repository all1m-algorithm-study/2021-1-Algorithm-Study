n = int(input())
connect = int(input())
com_lst = [[] for i in range(n+1)]
for i in range(connect):
    a, b = map(int, input().split())
    com_lst[a].append(b)
    com_lst[b].append(a)
visited = [ False for i in range(n+1)]

def DFS(graph, start, visited):
    if visited[start]:
        return
    visited[start] = True
    for i in graph[start]:
        DFS(graph, i, visited)

DFS(com_lst, 1, visited)

cnt = 0
for i in visited:
    if i:
        cnt += 1
print(cnt-1)
