import sys
sys.setrecursionlimit(10**7)


N = int(input())
graph = [[] for i in range(N+1)]

for i in range(N-1):
    (a,b) = list(map(int, input(). split()))
    graph[a].append(b)
    graph[b].append(a)


def DFS(graph, visited, start, parent):       
    if visited[start]:
        return

    visited[start] = True

    for dest in graph[start]:
        parent += [[dest, start]]
        graph[dest].remove(start)
        DFS(graph, visited, dest, parent)
    return parent

visited = [False] *(N+1)

parent = DFS(graph, visited, 1, [])

answer = sorted(parent, key=lambda parent: parent[0])

for i in range(N-1):
    print(answer[i][1])