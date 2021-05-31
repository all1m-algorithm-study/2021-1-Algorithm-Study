n = int(input())
man1, man2 = map(int, input().split())
relation_num = int(input())

graph = [ [] for i in range(n+1) ]
for i in range(relation_num):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [ False for i in range(n+1)]
cnt = 0
flag = True

def DFS(graph, start, visited, target, cnt):
    global flag
    if visited[start]:
        return
    if start == target:
        print(cnt)
        flag = False
        return
    
    visited[start] = True
    cnt += 1
    for i in graph[start]:
        DFS(graph, i, visited, target, cnt)

DFS(graph, man1, visited, man2, cnt)
if flag:
    print(-1)
